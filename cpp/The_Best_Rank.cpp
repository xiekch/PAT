#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Student {
    int id;
    float scores[4] = {0};
    int rank[4] = {0};
};

class Solution {
    char symbol[4] = {'A', 'C', 'M', 'E'};

  public:
    void solve() {
        int studentsNum, queriesNum;
        cin >> studentsNum >> queriesNum;
        map<int, int> mapping;
        vector<Student> students;
        for (int i = 0; i < studentsNum; i++) {
            Student stu;
            cin >> stu.id >> stu.scores[1] >> stu.scores[2] >> stu.scores[3];
            stu.scores[0] = (stu.scores[1] + stu.scores[2] + stu.scores[3]) / 3;
            students.push_back(stu);
        }

        for (int i = 0; i < 4; i++) {
            sort(students.begin(), students.end(), [i](Student &a, Student &b) {
                return a.scores[i] > b.scores[i];
            });
            students[0].rank[i] = 1;
            for (int j = 1; j < studentsNum; j++) {
                if (students[j].scores[i] == students[j - 1].scores[i]) {
                    students[j].rank[i] = students[j - 1].rank[i];
                } else {
                    students[j].rank[i] = j + 1;
                }
            }
        }
        
        for (int i = 0; i < studentsNum; i++) {
            mapping[students[i].id] = i;
        }

        int id;
        for (int i = 0; i < queriesNum; i++) {
            cin >> id;
            if (mapping.count(id) == 0) {
                printf("N/A\n");
            } else {
                Student stu = students[mapping[id]];
                int rank = 0;
                for (int j = 1; j < 4; j++) {
                    if (stu.rank[j] < stu.rank[rank]) {
                        rank = j;
                    }
                }
                printf("%d %c\n", stu.rank[rank], symbol[rank]);
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    sol.solve();
    return 0;
}
