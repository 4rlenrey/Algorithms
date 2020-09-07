//Task:
//https://szkopul.edu.pl/problemset/problem/VhUz-fNNGqUZBRoF9lNSvXTH/site/?key=statement

#include <iostream>
#include <vector>

using namespace std;

int main(){
  //input
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int miasta; //miasta numerujemy od 1 do miasta
  int koleje; //liczba par polaczonych miast koleja
  int miast_Pocz;
  int koszt_pociagu;
  int koszt_samolotu;

  cin >> miasta;
  cin >> koleje;
  cin >> miast_Pocz;
  cin >> koszt_pociagu;
  cin >> koszt_samolotu;

  // [miasto] [miasto polaczone z nim]
  int u;
  int v;

  vector<int>miasto[miasta+1];  


  for (int i = 1; i <= koleje; i++){
    cin >> u;
    cin >> v;  

    //kazde miasto ma w danych swoje polaczenia do innych
    miasto[u].push_back(v);
    miasto[v].push_back(u);  
  }

  cout << miasto[1][0] << "/n";


  return 0;
}