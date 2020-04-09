#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main() {

    string linea;
    char * pch;
    bool par = true;
    vector<int> posiciones;


    while(getline(cin, linea)){

        if(linea == ""){ break;}
        char * cstr = new char [linea.length()+1];
        strcpy (cstr, linea.c_str());
        posiciones.erase(posiciones.begin(), posiciones.end());

        pch = strchr(cstr,'"');


        while (pch!= nullptr)
        {
            posiciones.push_back(pch-cstr);
            if(par){cstr[pch-cstr]= 96; par = false;}
            else{cstr[pch-cstr]= 39; par = true;}
            pch=strchr(pch+1,'"');
        }

        for (int i = 0; i < linea.length() ; ++i) {
            for (int j = 0; j < posiciones.size() ; ++j) {
                if(cstr[i] == 39 and posiciones[j] == i ){cout << "'"; }
                if(cstr[i] == 96 and posiciones[j] == i){cout << "`";}
            }
            cout << cstr[i];
        }
        cout <<endl;
        delete[] cstr;
        delete[] pch;
    }
    return 0;
}
