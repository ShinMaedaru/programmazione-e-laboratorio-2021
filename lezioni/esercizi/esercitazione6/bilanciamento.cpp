#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

/*
SPIEGAZIONE: 
 considerando una stringa bilanciata quindi "()" o "(())" come zero perchè con "(" 
 sommo 1 mentre ")" sottraggo 1 pertanto se hanno lo stesso numero di parentesi 
 il risultato sarà sempre 0;
nel caso invece si presenti per prima una parentesi ")" 
il bilanciamento totale tenderà a -1 pertanto devo ribilanciare aggiungendo 1 
al bilanciamento per farlo tornare a 0 e sommare un altra variabile che definisce 
i passi in modo tale da far capire che ho aggiunto una parentesi
*/
int getMin(string s) {
    int bilanciamento = 0;
    int ris = 0;
  
    for (int i = 0; i < s.length(); ++i) {
  
        if(s[i] == '('){
            bilanciamento=bilanciamento+ 1;
        }else{
        bilanciamento = bilanciamento-1;
        }
          if (bilanciamento == -1) {
            ris = ris + 1;
            bilanciamento = bilanciamento + 1;
        }
    }
  
    return bilanciamento + ris;

}

int main()
{
    string s="()()";
    int result = getMin(s);

    cout << result << "\n";

    return 0;
}
