//
// Created by ladie on 07/06/2025.
//
#include <string>
#include <cctype>
// provavelmente deveria fazer uns comments aq pra melhorar a compreenção
using namespace std;
char to_lower(char c) {
    if (c>='A' && c<='Z') {
        return c+'a'-'A';
    }
    return c;
}
bool pangram(const string& s, string& m) {
    int letras[26] = {0};
    //pra metodos da string tenho de usar o size_t
    for (size_t i = 0; i<s.length(); i++) {
        char c = to_lower(s[i]);
        //kinda of que preciso decorar essa logica
        if (c>='a'&& c<='z') {
            letras[c-'a'] = 1;
        }
    }
    int final = 0;
    //quando dão a m só tenho de definir ela como vazia
    m ="";
    for (int i = 0; i<26; i++) {
        if (letras[i]==0) {
            m += (char) (i+'a');
            final=1;

        }
    }
    return final==0;



}