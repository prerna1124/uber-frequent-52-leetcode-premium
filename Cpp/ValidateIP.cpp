#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class ValidateIP {
private:
    string queryIP;
    int dot, colon;
public:
    ValidateIP(string ip) {
        queryIP = ip;
        dot = 0;
        colon = 0;
    }

    string validIPAddress() {
        for(char ch : queryIP) {
            if(ch == '.') dot += 1;
            if(ch == ':') colon += 1;
        }
        if(dot != 3 && colon != 7) return "Neither";
        if(dot > 0) {
            vector<string> values = split(queryIP, ".");
            if(values.size() != 4) return "Neither";
            for(int i = 0; i < values.size(); i++) {
                if(values[i].length() > 1 && values[i][0] == '0') {
                    return "Neither";
                }
                for(char ch : values[i]) {
                    if(!isdigit(ch)) {
                        return "Neither";
                    }
                }

                if(values[i].length() == 0 || values[i].length() > 3 || stoi(values[i]) < 0 || stoi(values[i]) > 255) {
                    return "Neither";
                }
                
            } 
            return "IPv4";
        }
        else {
            vector<string> values = split(queryIP, ":");

            if(values.size() != 8) return "Neither";

            for(int i = 0; i < values.size(); i++) {
                if(values[i].length() > 4 || values[i].length() == 0) {
                    return "Neither";
                }
                for(char ch : values[i]) {
                    if(!isdigit(ch) && (ch < 'a' || ch > 'f') && (ch < 'A' || ch > 'F')) {
                        return "Neither";
                    }
                }
            } 
            return "IPv6";
        }
    }

    vector<string> split(string s, string delimiter) {
        vector<string> parts;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            parts.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        parts.push_back(s);
        return parts;
    }
};

int main() {
    ValidateIP validator("172.16.254.1");
    cout << validator.validIPAddress() << endl;

    validator = ValidateIP("2001:db8:85a3:0:8a2E:0370:7334:0370");
    cout << validator.validIPAddress() << endl;

    validator = ValidateIP("2001:db8:85a3:0::8a2E:0370:7334:");
    cout << validator.validIPAddress() << endl;

    validator = ValidateIP("1e1.4.5.6");
    cout << validator.validIPAddress() << endl;

    return 0;
}
