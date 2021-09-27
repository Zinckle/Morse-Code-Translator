
#include <string>
#include <iostream>
using namespace std;

string morseCharToText(string morse) {
    // this function uses a binary tree to convert from english to morse code

    /* This is a represention of a morse code tree where the start of the tree is the ! symbol
    * The binary tree image I used can be found here: https://commons.wikimedia.org/wiki/File:Morse-code-tree.svg */
    string tree = "5H4S_V3I_F_U__2E_L_R+__A_P_W_J1!6B=D/X_N_C_K_Y_T7Z_G_Q_M8__O9_0";
    string out;
    int pos = tree.length()/2;
    int i = 0;

    while (i <  morse.length()) {
        //shifts the position if the char is a dot
        if (morse[i] == '.') {
            tree.erase(pos, tree.length());
            pos = tree.length()/2;
            out = tree[pos];
           // cout << out << "\n";
            i++;
        }
        ////shifts the position if the char is a dash
        else if(morse[i] == '-'){
            tree.erase(0, pos);
            pos = tree.length()/2;
            out = tree[pos];
           // cout << out << "\n";
            i++;
        }
        //the only other char to be passed in would be a dash which represents a space
        else {
            out = ' ';
            i++;
        }
    }

    return out;
}

string morseToText(string text) {

    int spacecount = 0;

    for (int j = 0; j < text.length(); j++) {
        if (text[j] == ' ') spacecount++;
    }

    int locate = 0;
    string holder = " ";
    int i = 0;
    string conversion = "";
    conversion.resize(spacecount + 1);

    while (i < spacecount + 1) {
        locate = text.find(' ');
        string pass = text.substr(0, locate);
        holder = morseCharToText(pass);
        conversion[i] = holder[0];
        text.erase(0, locate + 1);
        i++;
    }

    return conversion;

}

string textCharToMorse(char text)` {

    int test = 0;
    int test1 = text;
    text = toupper(test1);

    string temp = "!ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+=/ ";
    test = temp.find(text);

    string out = " ";
    switch (test)
    {
    case 1: out = ".- "; break;
    case 2: out = "-... "; break;
    case 3: out = "-.-. "; break;
    case 4: out = "-.. "; break;
    case 5: out = ". "; break;
    case 6: out = "..-. "; break;
    case 7: out = "--. "; break;
    case 8: out = ".... "; break;
    case 9: out = ".. "; break;
    case 10: out = ".--- "; break;
    case 11: out = "-.- "; break;
    case 12: out = ".-.. "; break;
    case 13: out = "-- "; break;
    case 14: out = "-. "; break;
    case 15: out = "--- "; break;
    case 16: out = ".--. "; break;
    case 17: out = "--.- "; break;
    case 18: out = ".-. "; break;
    case 19: out = "... "; break;
    case 20: out = "- "; break;
    case 21: out = "..- "; break;
    case 22: out = "...- "; break;
    case 23: out = ".-- "; break;
    case 24: out = "-..- "; break;
    case 25: out = "-.-- "; break;
    case 26: out = "--.. "; break;
    case 27: out = ".---- "; break;
    case 28: out = "..--- "; break;
    case 29: out = "...-- "; break;
    case 30: out = "....- "; break;
    case 31: out = "..... "; break;
    case 32: out = "-.... "; break;
    case 33: out = "--... "; break;
    case 34: out = "---.. "; break;
    case 35: out = "----. "; break;
    case 36: out = "----- "; break;
    case 37: out = ".-.-. "; break;
    case 38: out = "-...- "; break;
    case 39: out = "-..-. "; break;
    case 40: out = "/ "; break;
    default:
        break;
    }

    return out;
}

string textToMorse(string text) {

    string out = "";
    for (int i = 0; i < text.length(); i++) {

        out.append(textCharToMorse(text[i]));
    }
    out.erase(out.length());
    return out;

}
int main()
{

    string text = ".... . .-.. .-.. --- / .-- --- .-. .-.. -..";
    cout << morseToText(text);

    string test1 = "hello world";
    cout << textToMorse(test1);

}

