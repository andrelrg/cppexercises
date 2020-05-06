#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    char c;
    vector<node *> children;
} Node;


Node *ctts;

void addName(string name){
    Node *aux = ctts;
    bool find;
    for (char &ch : name){
        find = false;
        for (Node *n : aux->children){
            if (n == NULL) break;
            if (n->c == ch){
                find = true;
                aux = n;
            }
        }
        if (!find){
            Node *nN = new Node;
            nN->c = ch;
            aux->children.push_back(nN);
            aux = nN;
        }
    }
}

void findPartial(string name){
    Node *aux = ctts;
    int count = 0;
    bool first = true;
    for (char &ch : name){
        bool found = false;
        for (Node *n : aux->children){
            if (n->c == ch){
                found = true;
                aux = n;
                if (first){
                    first = false;
                    break;
                }
                count++;
            }
        }
        if (!found){
            count = 0;
            break;
        }
    }

    cout << count << endl;
    
}

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries) {
    /*
     * Write your code here.
     */
    ctts = new Node;
    vector<int> contacts;

    for(vector<string> &it: queries){
        if (it[0] == "add")
            addName(it[1]);
        else if (it[0] == "find")
            findPartial(it[1]);
    }

    return contacts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
