#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream> 
#include <cctype>  
#include<conio.h>
using namespace std;
class AiChatbot{
public:
string trimming(const string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == string::npos || end == string::npos)
        return ""; 
    return str.substr(start, end - start + 1);
}
vector<string> splitting(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == delimiter) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += str[i];
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}
string calculation(const string &operation, double num1, double num2) {
    double result;

    if (operation == "+") {
        result = num1 + num2;
    } else if (operation == "-") {
        result = num1 - num2;
    } else if (operation == "*") {
        result = num1 * num2;
    } 
	 else if (operation == "/") {
        if (num2 != 0) {
            result = num1 / num2;
        } 
		else {
            return "Division by zero is not allowed.";
        }
    }
	 else {
        return "Invalid operation";
    }

    ostringstream oss;
    oss << "The result of " << num1 << " " << operation << " " << num2 << " is " << result;
    return oss.str();
}


string tell_time() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    ostringstream oss;
    oss << "The current time is " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
    return oss.str();
}};

int main() {

system("color 30");
cout<<" ______________________________________________"<<endl;
cout<<"|                                              |"<<endl;
cout<<"|          ||   AI-CHATBOT  ||                 |"<<endl;
cout<<"|______________________________________________|\n"<<endl;
cout<<"                  LOGIN   "<<endl;
cout<<"      |--------------------------------|"<<endl;
string user;
cout<<"Username :";
cin>>user;
cout<<"Password : ";
if(user=="chatuser"){   
string a="";
 string b="ai-chat1";
 char c;
 for(int i=0;i<1000;i++)
	{
	 c=getch();
	 if(c=='\r')
		break;
	 cout<<"*";
	 a+=c;
	}
	if(a==b){
    AiChatbot a1;
    map<string, string> responses;
    responses["hello"] = "Hello! How can I help you?";
    responses["hi"] = "Hi there! How can I help you?";
    responses["how are you"] = "I'm an AI, so I don't have feelings, but I'm here to help you. What do you need?";
    responses["bye"] = "Goodbye! Have a great day!";
    responses["quit"] = "Goodbye! Have a great day!";
    responses["what's your name"] = "I'm an AI, and I don't have a name.";
    responses["who are you"] = "I'm an AI, and I'm here to help you.";
    responses["what can you do"] = "I can help you with various tasks, such as answering questions, providing information, performing calculations, telling the time, and opening links.";
    responses["can you help me with my homework"] = "Sure! I can help you with your homework. What do you need help with?";
    responses["can you calculate this"] = "Sure! What arithmetic operation would you like to perform? Please enter '+', '-', '*', or '/'.";
    responses["can you tell me the time"] = "Sure! " + a1.tell_time();
    responses["open google"] = "Opening Google... <https://www.google.com>";
    responses["open youtube"] = "Opening YouTube... <https://www.youtube.com>";
    responses["open instagram"] = "Opening Instagram... <https://www.instagram.com>";
    responses["open facebook"] = "Opening Facebook... <https://www.facebook.com>";
    responses["can you tell me a joke"] = "Why did the chicken cross the road? To get to the other side!";
    while (true) {
        cout << "You: ";
        string input;
        getline(cin, input);
string trimmedInput = a1.trimming(input);
if (!trimmedInput.empty()) {
    map<string,string>::iterator it = responses.find(trimmedInput);
    if (it != responses.end()) {
        cout << "AI: " << it->second << endl;
    } else if (trimmedInput.find("calculate") != string::npos) {
        cout << "AI: " << responses["can you calculate this"] << endl;
        cout << "You: ";
        string operation;
        getline(cin, operation);
        cout << "AI: Please enter the first number: ";
        double num1, num2;
        cin >> num1;
        cout << "AI: Please enter the second number: ";
        cin >> num2;
        cout << "AI: " << a1.calculation(operation, num1, num2) << endl;
       while (cin.peek() != '\n' && cin.peek() != EOF) {
    cin.ignore();
}

    } else {
        cout << "AI: Sorry, I didn't understand that." << endl;
    }
} else {
    cout << "\nAI: Please provide some input." << endl;
}
}}
else{
	cout<<"\nwrong  password!"<<endl;}
}
else{
	cout<<"\nwrong  username!"<<endl;}}
