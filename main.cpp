#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>

using namespace std;

vector< vector<int> > g; // Lista de Adjac�ncia

int transf(string z){
//    return ((z[0]-96) + ((z[1]-48)*8)) -8;
    return (z[0]-'a')*8 + z[1]-'0';
}
void noVetor(string x){
    string w = "aa";
    if(('a'<= x[0]-1 && '8'>=x[1]+2)){
        w[0]=x[0]-1;
        w[1]=x[1]+2;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }

    if(('h'>= x[0]+1 && '1'<=x[1]-2)){
        w[0]=x[0]+1;
        w[1]=x[1]-2;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }
    if(('h'>= x[0]+1 && '8'>=x[1]+2)){
        w[0]=x[0]+1;
        w[1]=x[1]+2;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }
    if(('a'<= x[0]-1 && '1'<=x[1]-2)){
        w[0]=x[0]-1;
        w[1]=x[1]-2;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }
    if(('h'>= x[0]+2 && '8'>=x[1]+1)){
        w[0]=x[0]+2;
        w[1]=x[1]+1;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }
    if(('h'>= x[0]+2 && '1'<=x[1]-1)){
        w[0]=x[0]+2;
        w[1]=x[1]-1;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }
    if(('a'<= x[0]-2 && '8'>=x[1]+1)){
        w[0]=x[0]-2;
        w[1]=x[1]+1;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }
    if(('a'<= x[0]-2 && '1'<=x[1]-1)){
        w[0]=x[0]-2;
        w[1]=x[1]-1;
        g[transf(x)].push_back(transf(w));
//        if (g[transf(x)].back() == f) return;
    }
}


//// Algoritmo calcula a menor distancia para alcan�ar todos os vertices do grafo partindo de um vertice inicial.
int bfs(int inicio,int final)
{
//    int yy = transf(inicio);
    //para os 3 vetores a seguir, cada posi��o do vetor representa um vertice do grafo.
    vector<int> d(g.size(), -1); // Vetor de dist�ncia minima para alcan�ar o vertice.
    vector<bool> cor(g.size(), false); // Define se cada vertice ja foi encontrado ou n�o.

    queue<int> Q; // Fila que define a ordem de acesso aos vertices.

    cor[inicio] = true; // Define a cor do v�rtice raiz como acessado.
    d[inicio] = 0; // Define a dist�ncia da raiz para ela mesma como 0.

    Q.push(inicio);

    while(!Q.empty())
    {
        int u = Q.front(); // Define u como sendo o v�rtice na frente na fila.
        Q.pop(); // Desenfileira.
//        cout<<"vertice atual: "<<u<<endl;
        // Para todo vertice adjacente � "u".
        for(int i = 0; i < g[u].size(); i++)
        {
//            int xx = transf(g[u][i]);
            // Se o vertice adjacente � "u" n�o tiver sido encontrado.
            if(cor[g[u][i]] == false)
            {
                d[g[u][i]] = d[u]+1; // Define a distancia minima para alcan�ar o vertice.
                if(g[u][i] == final) return d[final];
                Q.push(g[u][i]);
                cor[g[u][i]] = true;
            }
        }
    }
}

int main()
{
    string N,M;
    string x = "aa";
    g.resize(65);
    for(char c = 'a'; c<'i'; c++){
        for(char num = '1'; num<'9'; num++){
            x[0] = c;
            x[1]=num;
            noVetor(x);
//            cout<<"no "<<x<<" Tem:"<<endl;
//            for(int i=0; i<g[transf(x)].size(); i++ ){
//                cout<<g[transf(x)][i]<<endl;
//            }
        }
    }

    int h =0;
    int a,b;
    while(cin>>N>> M) {
        a = transf(N);
        b = transf(M);
        if(N!=M)cout << "To get from " << N << " to " << M << " takes " << bfs(a, b) << " knight moves."<<endl;
        else cout << "To get from " << N << " to " << M << " takes " <<0<< " knight moves."<<endl;
    }
    return 0;
}
