class Solution {
public:

    /*
    *   For each bar, we want to find:
    *   How far we can extend to the left → Previous Smaller Index (PSI)
    *    How far we can extend to the right → Next Smaller Index (NSI)
    *    Why? Because the bar’s height stays constant, but we want the widest width possible where no bar is shorter.
    */

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        int nsi[n]; // just-next smaller index
        stack<int> st1;
        nsi[n-1]=n;
        st1.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st1.size()>0 && heights[st1.top()]>=heights[i]) st1.pop();
            if(st1.size()==0) nsi[i]=n;
            else nsi[i]=st1.top(); 
            st1.push(i);
        }

        int psi[n]; // just-previous smaller index
        stack<int> st2;
        psi[0]=-1;
        st2.push(0);
        for(int i=1;i<n;i++){
            while(st2.size()>0 && heights[st2.top()]>=heights[i]) st2.pop();
            if(st2.size()==0) psi[i]=-1;
            else psi[i]=st2.top();
            st2.push(i); 
        }

        int maxA=0;
        for(int i=0;i<n;i++){
            int h=heights[i];
            int b=nsi[i]-psi[i]-1; // all the indices bw nsi[i] & psi[i] would be having height equal to or greater than 'h'
            int A=h*b; // hence since we have removed the smaller height indices, the area is simply height*(largest breadth possible)
            maxA=max(A,maxA);
        }
        return maxA;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++; //increment the height by 1
                else height[j]=0; //bring the height back to zero
            }
            int Area=largestRectangleArea(height); //calculate the max height of current rectangle 
            maxArea=max(maxArea,Area); // all time max area
        }
        return maxArea;
    }
};