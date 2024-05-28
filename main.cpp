
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("grafurineorientate.in");

int n, x[101][101], a, b,m,c1,c2;
int viz[101];

bool verificaLant(const vector<int>& lant) {
    for (size_t i = 0; i < lant.size() - 1; ++i) {
        if (x[lant[i]][lant[i + 1]] == 0) {
            return false;
        }
    }
    return true;
}

bool verificaLantElementar(const vector<int>& lant) {
    vector<bool> vizitat(n + 1, false);
    for (int nod : lant) {
        if (vizitat[nod]) {
            return false;
        }
        vizitat[nod] = true;
    }
    return verificaLant(lant);
}

bool verificaCiclu(const vector<int>& ciclu) {
    if (ciclu.size() < 3) {
        return false;
    }
    if (ciclu.front() != ciclu.back()) {
        return false;
    }
    vector<int> lant(ciclu.begin(), ciclu.end() - 1);
    return verificaLantElementar(lant);
}

void citesteSiVerificaLant() {
    int k;
    cout << "Introduceti lungimea lantului: ";
    cin >> k;
    vector<int> lant(k);
    cout << "Introduceti lantul: ";
    for (int i = 0; i < k; ++i) {
        cin >> lant[i];
    }
    if (verificaLant(lant)) {
        cout << "Succesiunea reprezinta un lant.";
    } else {
        cout << "Succesiunea nu reprezinta un lant.";
    }
    cout << endl;
}

void citesteSiVerificaLantElementar() {
    int k;
    cout << "Introduceti lungimea lantului elementar: ";
    cin >> k;
    vector<int> lant(k);
    cout << "Introduceti lantul elementar: ";
    for (int i = 0; i < k; ++i) {
        cin >> lant[i];
    }
    if (verificaLantElementar(lant)) {
        cout << "Succesiunea reprezinta un lant elementar.";
    } else {
        cout << "Succesiunea nu reprezinta un lant elementar.";
    }
    cout << endl;
}

void citesteSiVerificaCiclu() {
    int k;
    cout << "Introduceti lungimea ciclului: ";
    cin >> k;
    vector<int> ciclu(k);
    cout << "Introduceti ciclul: ";
    for (int i = 0; i < k; ++i) {
        cin >> ciclu[i];
    }
    if (verificaCiclu(ciclu)) {
        cout << "Succesiunea reprezinta un ciclu.";
    } else {
        cout << "Succesiunea nu reprezinta un ciclu.";
    }
    cout << endl;
}


void afiseazaCicluriLungime4() {
    bool cicluriGasite = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (x[i][j]) {
                for (int k = j + 1; k <= n; ++k) {
                    if (x[j][k]) {
                        for (int l = k + 1; l <= n; ++l) {
                            if (x[k][l] && x[l][i]) {
                                cout << "Ciclu de lungime 4: " << i << " " << j << " " << k << " " << l << " " << i << endl;
                                cicluriGasite = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if (!cicluriGasite) {
        cout << "Nu exista cicluri de lungime 4 in graf." << endl;
    }
}




void noduriincidente(int k) {
    int count = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(x[i][j] == 1)
            {

                count++;
                if(count == k) {
                    cout << "Nodurile incidente cu cea de a " << k << "-a muchie a grafului sunt: " << i << " si " << j;
                    return;
                }
            }
        }
    }
    cout << "Nu exista a " << k << "-a muchie in graf." << endl;
}


void verif_ciclu(int a[101][101], int n) {
    int k[101], p;

    cout <<"Introduceti numarul de noduri: ";
    cin >> p;
    cout <<"Introduceti nodurile care trebuie vizitate: ";
    for (int i = 1; i <= p; ++i) {
        cin >> k[i];
    }


    if (p < 2 || k[1] != k[p]) {
        cout << "Nu este un ciclu";
        return;
    }


    bool visited[101] = {false};
    visited[k[1]] = true;
    for (int i = 2; i < p; ++i) {
        if (k[i] < 1 || k[i] > n || visited[k[i]]) {
            cout << "Nu este un ciclu";
            return;
        }
        visited[k[i]] = true;
    }

    cout << "Este un ciclu";
}


void dfs(int k, int *v)
{
    v[k] = 1;
    v[1001]++;
    for (int i = 1; i <= n; i++)
        if (x[k][i] == 1 && v[i] == 0)
        {
            dfs(i, v);
        }
}

int cerinta19()
{
    int v[1002] = {0};
    dfs(1, v);
    if (v[1001] == n)
        return 1;
    else
        return 0;
}


void cerinta20()
{
     if (cerinta19() == 0)
         cout << "Nu e arbore!" << '\n';
     else
          cout << "E arbore!" << '\n';
}


void noduriadiacente(int k)
{
   for(int i = 1; i <= n; i++) {
        if(x[k][i]==1)
        cout<<i<<" ";
    }
}

void gradmaxsimin() {
    int grad_minim = n;
    int grad_maxim = 0;
    int noduri_grad_minim = 0;
    int noduri_grad_maxim = 0;

    for (int i = 1; i <= n; i++) {
        int grad_nod = 0;
        for (int j = 1; j <= n; j++) {
            if (x[i][j] == 1) {
                grad_nod++;
            }
        }

        if (grad_nod < grad_minim) {
            grad_minim = grad_nod;
            noduri_grad_minim = 1;
        } else if (grad_nod == grad_minim) {
            noduri_grad_minim++;
        }

        if (grad_nod > grad_maxim) {
            grad_maxim = grad_nod;
            noduri_grad_maxim = 1;
        } else if (grad_nod == grad_maxim) {
            noduri_grad_maxim++;
        }
    }

    cout << "Nodurile de grad minim sunt: ";
    for (int i = 1; i <= n; i++) {
        int grad_nod = 0;
        for (int j = 1; j <= n; j++) {
            if (x[i][j] == 1) {
                grad_nod++;
            }
        }
        if (grad_nod == grad_minim) {
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Nodurile de grad maxim sunt: ";
    for (int i = 1; i <= n; i++) {
        int grad_nod = 0;
        for (int j = 1; j <= n; j++) {
            if (x[i][j] == 1) {
                grad_nod++;
            }
        }
        if (grad_nod == grad_maxim) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void noduriterminale() {
    int noduri_terminale = 0;
    cout<<"Nodurile terminale sunt: ";
    for (int i = 1; i <= n; i++) {
        int grad_nod = 0;
        for (int j = 1; j <= n; j++) {
            if (x[i][j] == 1) {
                grad_nod++;
            }
        }
        if(grad_nod == 1) {
            cout << i << " ";
            noduri_terminale++;
        }
    }
    if (noduri_terminale == 0) {
        cout << "nu exista noduri terminale.";
    }
    cout << endl;
}



void matricea_de_adiacenta ()
{

cout<<"Matricea de adiacenta a grafului este:"<<endl;
    for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
                {
                    cout << x[i][j] << " ";
            }cout << endl;
        }
}

void grad_nod(int k)
{
    int g[101];
      for(int i = 1 ;  i <= n ; i++){
        g[i] = 0;
        for(int j = 1; j <= n ; j++)
            if(x[i][j] == 1)
                g[i] ++;
    }
    cout<<g[k];
}


void noduri_izolate()
{
    int g[101];
     for(int i = 1 ;  i <= n ; i++){
        g[i] = 0;
        for(int j = 1; j <= n ; ++j)
            if(x[i][j] == 1)
                g[i] ++;
    }


    for(int i = 1 ;  i <= n ; i++)
    {
        if(g[i] == 0)
            cout << i << " ";
    }

}


void dfs(int nod)
{
    viz[nod]=1;
    cout<<nod<<' ';
    for(int i=1;i<=n;i++)
        if(x[nod][i]==1 && viz[i]==0)
        dfs(i);

}

void BFS(int nod)
{
    int p = 0, u = 0, q[1001], viz[1001] = {};
    q[0] = nod;
    viz[nod] = 1;
    while (p <= u)
    {
        nod = q[p];
        p++;
        cout << nod << " ";
        for (int i = 1; i <= n; i++)
        {
            if (x[i][nod] == 1 && viz[i] == 0)
            {
                viz[i] = 1;
                u++;
                q[u] = i;
            }
        }
    }
}

void lantelementar(int c1, int c2, int *L, int *X, int k, int ok)
{
    for (int i = 1; i <= n; i++)
    {
        if (!L[i])
        {
            L[i] = 1;
            X[k] = i;
            if (k == 1 || x[X[k - 1]][X[k]] == 1)
            {
                if (X[k] == c2)
                {
                    ok = true;
                    cout << "Lantul este:";
                    for (int j = 1; j <= k; j++)
                        cout << X[j] << " ";
                    cout << '\n';
                    return;
                }
                else if (!ok)
                {
                    lantelementar(c1, c2, L, X, k + 1, ok);
                }
            }
            L[i] = 0;
        }
    }
}

int cerinta10()
{
    int v[101]={0};
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
    {
    if(x[ i][j]==1)
    if(v[i]==1 && v[j]==1)
    return 1;
    else
    {
    v[i]=1;v[j]=1;
    }
    }
    return 0;
}

void op9(int x1, int* vizat)
{
    vizat[x1]=1;
    cout<<x1<<" ";

    for(int i = 1; i <= n; i++){
        if(x[x1][i] == 1 && vizat[i]==0)
        {
            op9(i,vizat);
        }
    }
}

int main() {
    fin >> n;
    while(fin >> a >> b) {
        x[a][b] = 1;
        x[b][a] = 1;
    }
    cout << "\nMeniu:" << endl;
    cout << "1. Afiseaza matricea de adiacenta" << endl;
    cout << "2. Afiseaza, pentru un nod citit, gradul nodului" << endl;
    cout << "3. Afiseaza nodurile incidente cu a k-a muchie" << endl;
    cout << "4. Afiseaza nodurile adiacente pentru un nod dat" << endl;
    cout << "5. Afiseaza nodurile de grad maxim, respectiv minim" << endl;
    cout << "6. Afiseaza nodurile izolate" << endl;
    cout << "7. Sa se afiseze nodurile terminale" << endl;
    cout << "8. Sa se afiseze un lant elementar de la nodul x la y" << endl;
    cout << "9. Citeste un nod x si afiseaza toate nodurile legate printr-un lant de x" << endl;
    cout << "10. Verifica daca gradul are cicluri" << endl;
    cout << "11. Sa se verifice daca exista un lant de lungime 4" << endl;
    cout << "12. Parcurgere DFS" << endl;
    cout << "13.BFS"<<endl;
    cout << "14. lant" << endl;
    cout << "15. lant elementar" << endl;
    cout << "16. ciclu" << endl;
    cout << "17. verifica ciclu" << endl;
    cout << "19. Sa se verifice daca graful este conex" << endl;
    cout << "20. Sa se verifice daca graful este un arbore" << endl;
    cout << "0. Iesire" << endl;

    int option;
    cout << "Alege optiunea: ";
    cin >> option;
    switch(option) {

       case 1: {
            matricea_de_adiacenta();
            break;
        }
      case 2: {
          int k;
	cout<< "Introduceti nodul dorit:";
	cin>>k;
	if(k>n)
    {
        cout<<"Nodul nu exista!";
        break;
    }
    else
           grad_nod (k);
            break;
        }


        case 3: {
            int k;

            cout << "Introduceti indexul muchiei (k): ";
            cin >> k;
            noduriincidente(k);
            break;
        }
        case 4: {
            int k;
            cout<<"Introduceti nodul dorit: ";
            cin>>k;
            cout<<"Nodurile adiacente sunt: ";
            noduriadiacente(k);
            break;
        }
        case 5:{
            gradmaxsimin( );
            break;
        }
       case 6: {
            noduri_izolate();
            break;
        }
        case 7:{
            noduriterminale();
            break;
     }

 case 8:
        {
            cout << "Introduceti cele doua noduri:";
            cin >> c1 >> c2;
            int L[1001] = {0}, X[1001] = {0};
            bool ok = false;
            L[c1] = 1;
            X[1] = c1;
            lantelementar(c1, c2, L, X, 2, ok);
            break;
        }


        case 9:
        {
            int ponct,vizat[101]={0};
            cin>>ponct;
            op9(ponct,vizat);
            break;
        }
        case 10:
        {
            if (cerinta10() == 1)
                cout << "Exista cicluri" << endl;
            else
                cout << "Nu exista cicluri" << endl;
            break;
       case 11:
	  {
		afiseazaCicluriLungime4();
		break;
	  }
      case 12:
 {
                int x0;
                cout<<"Numarul de muchii al grafului este:";
                cin>>m;
                cout<<"Nodul din care va incepe parcurgerea grafului este:";
                cin>>x0;
                dfs(x0);
                break;
        }

       case 13: // parcurgere bfs
        {
            int k;
            cin >> k; // nodul din care incepe parcurgerea
            BFS(k);
            break;
        }
	case 14:
	  {
		citesteSiVerificaLant();
		break;
	  }
	case 15:
	  {
		citesteSiVerificaLantElementar();
		break;
	  }
	case 17:
        {
        	int p;
        	verif_ciclu(x,n);
        	break;
        }
	case 16:
	  {
		citesteSiVerificaCiclu();
		break;
	  }
	case 19:
	  {
              if (cerinta19() == 1)
                cout << "Graful este conex!" << endl;
              else
              	cout << "Graful nu este conex!" << endl;
		break;
	  }
	case 20:
	  {
		cerinta20 ();
		break;
	  }
        default: {
            cout << "Optiune invalida! Va rugam sa alegeti din nou." << endl;
            break;
        }
    }

    }
    return 0;

}

