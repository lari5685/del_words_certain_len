#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    char name_in[30];
    char name_out[30];
    int len;
    string line;
    string text;
    string buf;

    cout << "Введите имя входного файла :: ";
    cin >> name_in;
    cout << "Введите длину слов которых надо удалить :: ";
    cin >> len;
    cout << "Введите имя выходного файла :: ";
    cin >> name_out;

    ifstream fin(name_in);
    ofstream fout(name_out);

    if (!fin.is_open())
    {
        cout << "Ошибка при открытии файла\n\n" << endl;
        return -1;
    }
    string word;
    len += 1;
    while (!fin.eof())
    {
        char buf;
        fin.get(buf);
        word = "";
        while ('.' != buf && ',' != buf && '!' != buf && '?' != buf && '-' != buf && ':' != buf)
        {
            word += buf;
            fin.get(buf);
            if (' ' == buf) {
                break;
            }
            
        }
        word += buf;
        if (word.length() != len and word.length() > 0)
        {
            cout << word ;
            text += word ;
        }
        else {
            if (word[len - 1] == '.' || word[len - 1] == ',' || word[len - 1] == '!' || word[len - 1] == '?' || word[len - 1] == '-' || word[len - 1] == ':')
            {
                cout << word[len-1];
                text += word[len-1];
            }
        }
    }

    fout << text;
    
    fin.close();
    fout.close();
    cin >> word;
    return 0;
}