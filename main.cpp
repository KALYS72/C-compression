#include <bits/stdc++.h>
using namespace std;

struct file {
    void input () {
        ofstream fout("compressed.txt");
        if (!fout) {
            cerr << "Error opening file!" << endl;
        }
        string n;
        cout << "Enter value: ";
        cin >> n;
        n = compress(n);
        fout << n << endl;
        cout << "Compressed text: " << n << endl;
    }

    void outpit() {
        ifstream fout("compressed.txt");
        ofstream fit("decompressed.txt");
        string n;
        fout >> n;
        n = decompress(n);
        fit << n << endl;
        cout << "Decompressed text: " << n << endl;
    }

    string compress(string data) {
        string result;
        int count = 1;
        char current = data[0];
        for (int i = 1; i < data.length(); i++) {
            if (data[i] == current) {
                count++;
            } 
            else {
                result += to_string(count)+ "`" + current;
                count = 1;
                current = data[i];
            }
        }
        result += to_string(count) + "`" + current; 
        return result;
    }

    string decompress(string data) {
        string result;
        int current_number=0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] != '`') {
                if (current_number != 0) {
                    current_number = (current_number * 10) + (data[i] - '0');
                }
                else {
                    current_number = data[i] - '0';
                }
            }
            else {
                char element = data[i+1];
                for (int j = 0; j < current_number; j++) {
                    result += element;
                }
                current_number = 0;
                i++;
            }
        }
        return result;
    }
};

int main() {
    file me;
    me.input();
    me.outpit();
}