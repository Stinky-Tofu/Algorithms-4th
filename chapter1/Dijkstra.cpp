//
//  Dijkstra.cpp
//  code
//
//  Created by StinkyTofu on 2021/3/13.
//

#include "Dijkstra.hpp"

#include <string>
#include <stack>
#include <vector>
#include <set>
#include <iostream>

#include "utils.hpp"

double Dijkstra(const std::string& str){
    std::vector<std::string> strSplited;
    splitStr(str, strSplited);
    
    std::stack<std::string> opStack;
    std::stack<double> valStack;
    std::set<std::string> ops{"+", "-", "*", "/"};
    
    for (const std::string& s: strSplited){
        if (s == "("){
            continue;
        }
        else if (ops.count(s)){
            opStack.push(s);
        }
        else if (s == ")"){
            const double val0 = valStack.top();
            valStack.pop();
            const double val1 = valStack.top();
            valStack.pop();
            
            const std::string op = opStack.top();
            opStack.pop();
            
            if (op == "+"){
                valStack.push(val1 + val0);
            }
            else if (op == "-"){
                valStack.push(val1 - val0);
            }
            else if (op == "*"){
                valStack.push(val1 * val0);
            }
            else if (op == "/"){
                valStack.push(val1 / val0);
            }
        }
        else{
            valStack.push(std::stof(s));
        }
    }
    
    return valStack.top();
}


void DijkstraTest(){
    std::string str = "( ( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) ) + ( ( 1 + 5 ) / 2 ) )";
    double result = 0.0;
    result = Dijkstra(str);
    std::cout << result << std::endl;
}
