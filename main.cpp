#include "mtree.cpp"

int main() {
    Mtree mtree{5};
    int N;
    cin>>N;
    float i=0;
    while(N--){
        string a; 
        cin>>a;
        int x, y;
        cin>>x>>y;
        float features[2] = {i+1, i+2};
        Embedding emb = {features, 2, a};
        mtree.addObject(emb);
        i++;
    }
    printTree(mtree);
    float features[2] = {2,3};
    Embedding embedding = {features, 2, "Peru"};
    vector<Embedding> results = queryRange(mtree.root, embedding, 3);
    cout<<"/n/nResultados: "<<endl;
    for(Embedding i : results){
        printEmbedding(i);
    }
    cout<<"/n/nEl otro: "<<endl;
    set<string> indexResults = diversedQueryRange(mtree, embedding, 10, 4);
    cout << "Search done" << endl;
    for (auto embeddingResult : indexResults)
        cout << embeddingResult << " ";
}
