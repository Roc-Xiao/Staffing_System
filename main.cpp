#include <iostream>
#include <vector>
#include <string>
#include <map>

//三种不同部门
#define MEISHU 0
#define CEHUA 1
#define YANFA 2

class Staff {

    //员工的信息
public:
    std::string m_name;
    int m_salary;

};

//创建员工信息
void create_staff(std::vector<Staff> &v) {
    std::string nameSeed = "ABCDEFIJKL";
    for (int i = 0; i < 10; i++) {
        Staff staff;
        staff.m_name = "Staff";
        staff.m_name += nameSeed[i];
        staff.m_salary = rand() % 10000 + 10000;
        v.push_back(staff);
    }
}

//员工分组
void setGroup(std::vector<Staff> &v, std::multimap<int, Staff> &m) {
    for (auto it = v.begin(); it != v.end(); it++) {
        //产生随机部门编号
        int deptId = rand() %3;

        //随机插入分组
        m.insert(std::make_pair(deptId, *it));
    }
}

//分组列表
void showStaff(std::multimap<int, Staff> &m) {

    //美术部门
    std::cout<< "美术部门： " << std::endl;
    std::multimap <int, Staff> :: iterator pos = m.find(MEISHU); //检索对应映射
    int count = m.count(MEISHU); //检测美术人数
    int index = 0;  //统计已检测出人数，降低时间复杂度

    for ( ; pos != m.end() && index != count; pos++, index++) {
        std::cout << "姓名： "<< pos->second.m_name << "  工资： " << pos->second.m_salary << std::endl;
    }
    std::cout <<"-----------------------" <<std::endl;


    //策划部门
    std::cout<< "策划部门： " << std::endl;
    pos = m.find(CEHUA); //检索对应映射
    count = m.count(CEHUA); //检测策划人数
    index = 0;  //统计已检测出人数，降低时间复杂度

    for ( ; pos != m.end() && index != count; pos++, index++) {
        std::cout << "姓名： "<< pos->second.m_name << "  工资： " << pos->second.m_salary << std::endl;
    }
    std::cout <<"-----------------------" <<std::endl;


    //研发部门
    std::cout<< "研发部门： " << std::endl;
    pos = m.find(YANFA); //检索对应映射
    count = m.count(YANFA); //检测研发人数
    index = 0;  //统计已检测出人数，降低时间复杂度

    for ( ; pos != m.end() && index != count; pos++, index++) {
        std::cout << "姓名： "<< pos->second.m_name << "  工资： " << pos->second.m_salary << std::endl;
    }
    std::cout <<"-----------------------" <<std::endl;

}
int main() {

    //创建员工
    std::vector<Staff>vStaff;
    create_staff(vStaff);

    //员工分组
    std::multimap<int, Staff> mStaff;
    setGroup(vStaff, mStaff);

    //分组展示员工
    showStaff(mStaff);

    return 0;
}