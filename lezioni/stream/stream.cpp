#include <sstream>
#include <string>

using namespace std;
//estrazione senza getline
int main(){
    string date ="2/04/2021";
    istringstream iss{date};
    int day,month,year;
    char sep; //temporaneo per separatori
    iss>>day>>sep>>month>>sep>>year;
    
}