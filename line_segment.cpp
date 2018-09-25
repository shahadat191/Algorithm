/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */

#include<bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

int check(point p1,point p2,point p3){
    
    int x1, x2,y1,y2;
    x1 = p2.x - p1.x;
    x2 = p3.x - p1.x;
    y1 = p2.y - p1.y;
    y2 = p3.y - p1.y;
    
    return x1*y2 - x2*y1;
}

bool online(point p1,point p2,point p3){
    
    if(p3.x >= min(p1.x, p2.x) && p3.x <= max(p1.x, p2.x) && p3.y>=min(p1.y, p2.y) && p3.y<=max(p1.y, p2.y))
        return true;
    return false;
}

bool intersect(point p1, point p2, point p3, point p4){
    
    int d1 = check(p1,p2,p3);
    int d2 = check(p1,p2, p4);
    int d3 = check(p3,p4,p1);
    int d4 = check(p3,p4,p2);
    
    if(((d1 > 0 && d2 < 0) || ( d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || ( d3 < 0 && d4 > 0)))
        return true;
    else if(d1 == 0 && online(p1,p2,p3)){
        return true;
    }
    else if(d2 == 0 && online(p1,p2,p4)){
        return true;
    }
    else if(d3 == 0 && online(p3,p4,p1)){
        return true;
    }
    else if(d4 == 0 && online(p3,p4,p2)){
        return true;
    }
    return false;
}




int main(){
    
}

