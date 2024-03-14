const int N = 3e5 + 5;
int timer = 0;
int tin[N];
int low[N];

int inStack[N];
vector<int> st;
vector<vector<int>> scc;
vector<int> sccId(N);
 
vector<int> adj[N];
 
void tarjan(int node)
{
	tin[node] = low[node] = timer++;
	inStack[node] = 1;
	st.push_back(node);
	
	for(auto &ch: adj[node])
	{
		if(tin[ch]==-1) tarjan(ch);
		if(inStack[ch]) low[node] = min(low[node], low[ch]);
	}
	
	if(low[node]==tin[node])
	{
		scc.push_back({});
		while(true)
		{
			int x = st.back();
			inStack[x] = 0;
			st.pop_back();
			scc.back().push_back(x);
			sccId[x] = scc.size()-1;
			if(x==node)break;
		}
	}
}
