//
// Created by wangzy on 2018/2/2.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int score;
    bool operator<(const Student &otherStudent){
        //成绩由低向高排序
        //如果成绩相等 则调用字典序name的排序
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
        //成绩由高向低排序
//        return score > otherStudent.score;
    }

    friend ostream& operator<<(ostream &os, const Student &otherStudent){
        os<<"Student: "<<otherStudent.name<<" "<<otherStudent.score<<endl;
        return os;
    }
};

#endif //SELECTIONSORT_STUDENT_H
