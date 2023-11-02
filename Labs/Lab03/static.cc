#include <iostream>
using namespace std;

/**
 * @author  Nicolas Dozmati
 * @brief   This program demonstrates the use of static variables.
 * @date    09-21-2123
*/

void pretty(){
    static int x = 0;

    x++;
    for(int i = 0; i < x; i++){
        cout << '*';
    }
    cout << endl;
}

int main(){

    for(int i = 0; i < 6; i++){
    pretty();
    }

    return 0;
}
