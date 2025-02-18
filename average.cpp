#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc,char *argv[]){
    int sum;
    if (argc == 1){
    cout << "Please input numbers to find average.\n";
    }else{
        for (int i = 0 ; i < argc ; i ++){
        sum += atof(argv[i]);
        }
        cout << "---------------------------------\n";
        cout << "Average of " << argc-1 << " numbers = " << sum/(argc-1);
        cout << "\n---------------------------------";
    }
    return 0;
}
