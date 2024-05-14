
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("grafurineorientate.in");

int n, x[101][101], a, b;


void grafuri_partiale(){
    
}

void arbore (int k)
{

  int viz[30], u, v, p, c[30], m = 0;

  for (int i = 1; i <= n - 1; i++)
	for (int j = i + 1; j <= n; j++)
	  {
		x[j][i] = x[i][j];
		m += x[i][j];
	  }

  for (int j = 1; j <= n; j++)
	viz[j] = 0;


  c[1] = k;
  p = 1;
  u = 1;
  viz[k] = 1;
  while (p <= u)
	{
	  v = c[p];
	  for (int i = 1; i <= n; i++)
		{

		  if ((x[v][i] == 1) && (viz[i] == 0))

			{

			  u++;
			  c[u] = i;
			  viz[i] = 1;

			}

		}
	  p++;
	}
  int arbore = 1;
  for (int i = 1; i <= n; i++)
	if (!viz[1])
	  arbore = 0;
  if (m == n - 1 && arbore)
	cout << "Graful este arbore";
  else
	cout << "Graful nu este arbore";
}

void conex ()
{
  int a[105], v[105], st, dr, cont=0;

  st = dr = 1;
  v[1] = 1;
  a[1] = 1;
  while (st <= dr)
	{
	  int t = a[st];
	  for (int i = 1; i <= n; ++i)
		if (v[i] == 0 && x[t][i] == 1)
		  {
			dr++;
			v[i] = 1;
			a[dr] = i;
		  }
	  st++;
	}
  for (int i = 1; i <= n; ++i){
	if (v[i] == 0)
	  cont++;
}
  if(cont==0)
    cout << "Graful este conex";
  else
    cout << "Graful nu este conex";
	    
}


void noduriincidente (int k)
{
  int count = 0;
  for (int i = 1; i <= n; i++)
	{
	  for (int j = i + 1; j <= n; j++)
		{
		  if (x[i][j] == 1)
			{

			  count++;
			  if (count == k)
				{
				  cout << "Nodurile incidente cu cea de a " << k <<
					"-a muchie a grafului sunt: " << i << " si " << j;
				  return;
				}
			}
		}
	}
  cout << "Nu exista a " << k << "-a muchie in graf." << endl;
}


void noduriadiacente (int k)
{
  for (int i = 1; i <= n; i++)
	{
	  if (x[k][i] == 1)
		cout << i << " ";
	}
}

void gradmaxsimin ()
{
  int grad_minim = n;
  int grad_maxim = 0;
  int noduri_grad_minim = 0;
  int noduri_grad_maxim = 0;

  for (int i = 1; i <= n; i++)
	{
	  int grad_nod = 0;
	  for (int j = 1; j <= n; j++)
		{
		  if (x[i][j] == 1)
			{
			  grad_nod++;
			}
		}

	  if (grad_nod < grad_minim)
		{
		  grad_minim = grad_nod;
		  noduri_grad_minim = 1;
		}
	  else if (grad_nod == grad_minim)
		{
		  noduri_grad_minim++;
		}

	  if (grad_nod > grad_maxim)
		{
		  grad_maxim = grad_nod;
		  noduri_grad_maxim = 1;
		}
	  else if (grad_nod == grad_maxim)
		{
		  noduri_grad_maxim++;
		}
	}

  cout << "Nodurile de grad minim sunt: ";
  for (int i = 1; i <= n; i++)
	{
	  int grad_nod = 0;
	  for (int j = 1; j <= n; j++)
		{
		  if (x[i][j] == 1)
			{
			  grad_nod++;
			}
		}
	  if (grad_nod == grad_minim)
		{
		  cout << i << " ";
		}
	}
  cout << endl;

  cout << "Nodurile de grad maxim sunt: ";
  for (int i = 1; i <= n; i++)
	{
	  int grad_nod = 0;
	  for (int j = 1; j <= n; j++)
		{
		  if (x[i][j] == 1)
			{
			  grad_nod++;
			}
		}
	  if (grad_nod == grad_maxim)
		{
		  cout << i << " ";
		}
	}
  cout << endl;
}

void noduriterminale ()
{
  int noduri_terminale = 0;
  cout << "Nodurile terminale sunt: ";
  for (int i = 1; i <= n; i++)
	{
	  int grad_nod = 0;
	  for (int j = 1; j <= n; j++)
		{
		  if (x[i][j] == 1)
			{
			  grad_nod++;
			}
		}
	  if (grad_nod == 1)
		{
		  cout << i << " ";
		  noduri_terminale++;
		}
	}
  if (noduri_terminale == 0)
	{
	  cout << "nu exista noduri terminale.";
	}
  cout << endl;
}










int main ()
{
  fin >> n;
  while (fin >> a >> b)
	{
	  x[a][b] = 1;
	  x[b][a] = 1;
	}
  cout << "\nMeniu:" << endl;
  cout << "1. Afiseaza matricea de adiacenta" << endl;
  cout << "2. Afiseaza, pentru un nod citit, gradul nodului" << endl;
  cout << "3. Afiseaza nodurile incidente cu a k-a muchie" << endl;
  cout << "4. Afiseaza nodurile adiacente pentru un nod dat" << endl;
  cout << "5. Afiseaza nodurile de grad maxim, respectiv minim" << endl;
  cout << "7. Sa se afiseze nodurile terminale" << endl;
  cout << "11. Sa se afiseze nodurile terminale" << endl;
  cout << "18. Sa se afiseze nodurile terminale" << endl;
  cout << "19. Sa se afiseze nodurile terminale" << endl;
  cout << "20. Sa se afiseze nodurile terminale" << endl;
  cout << "0. Iesire" << endl;

  int option;
  cout << "Alege optiunea: ";
  cin >> option;
  switch (option)
	{

	case 1:
	  {
		matricea_de_adiacenta ();
		break;
	  }

	case 3:
	  {
		int k;
		cout << "Introduceti indexul muchiei (k): ";
		cin >> k;
		noduriincidente (k);
		break;
	  }
	case 4:
	  {
		int k;
		cout << "Nodurile adiacente sunt: ";
		noduriadiacente (k);
		break;
	  }
	case 5:
	  {
		gradmaxsimin ();
		break;
	  }
	case 7:
	  {
		noduriterminale ();
		break;
	  }
	case 11:
	  {
	
		break;
	  }
	case 18:
	  {
        
		break;
	  }
	case 19:
	  {
        conex ();
		break;
	  }
	case 20:
	  {
	    int k;
		cout << "Introduceti nodul de plecare: ";
		cin >> k;
		arbore (k);
		break;
	  }
	default:
	  {
		cout << "Optiune invalida! Va rugam sa alegeti din nou." << endl;
		break;
	  }
	}

  return 0;
}
