vector<ll> dist(n,inf);
dist[src] = 0;
deque<int> q;
q.push_front(src);
while(!q.empty())
{
    int node = q.front();
    q.pop_front();

    for(auto &[ch,w]: adj[node])
    {
        if(dist[ch]<=dist[node]+w) continue;
        dist[ch] = dist[node]+w;

        if(w==1) q.push_back(ch);
        else q.push_front(ch);
    }
}