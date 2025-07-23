class Solution {
public:
    
vector<int> findValidOrdering(int numberOfCourses,vector<vector<int>> preReq){
	unordered_map<int,vector<int>> graph;
	vector<int> inDegree(numberOfCourses,0);

for(int startIndex=0;startIndex<preReq.size();++startIndex){
	int preReqCourse=preReq[startIndex][1];
	int finalCourse=preReq[startIndex][0];
	inDegree[finalCourse]++;
	graph[preReqCourse].push_back(finalCourse);
}

queue<int> avalaibleCourses;
for(int courses=0;courses<numberOfCourses;++courses){
	if(inDegree[courses]==0) avalaibleCourses.push(courses);
}


vector<int> ans;
while(avalaibleCourses.size()){
	int  currCourse=avalaibleCourses.front(); avalaibleCourses.pop();
	ans.push_back(currCourse);
	for(int finalCourses:graph[currCourse]){
		inDegree[finalCourses]--;
		if(inDegree[finalCourses]==0){
			avalaibleCourses.push(finalCourses);
		}
}
}

if(ans.size()==numberOfCourses)
 return ans;
return {};
}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return findValidOrdering(numCourses,prerequisites);
    }
};