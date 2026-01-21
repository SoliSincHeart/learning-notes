// binary.cpp -- 二进制文件 I/O
#include <iostream> // 对大多数系统来说不是必需的
#include <fstream>
#include <iomanip>
#include <cstdlib> // 为了 exit() 函数
#include <locale>   // 用于设置本地化

// 读取并忽略行中剩余的字符
inline void eatline() { while (std::cin.get() != '\n') continue; }

struct planet
{
    char name[20];      // 行星名称
    double population;  // 行星人口
    double g;           // 行星的重力加速度
};

const char* file = "planets.dat"; // 数据文件名

int main()
{
    // 设置本地化以支持中文输出
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale(""));

    using namespace std;
    planet pl;
    cout << fixed << right;

    // 显示初始内容
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary); // 以二进制模式打开文件
    // 注意：某些系统不接受 ios_base::binary 模式
    if (fin.is_open())
    {
        cout << "以下是 " << file << " 文件的当前内容：\n";
        while (fin.read((char*)&pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ":"
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    // 添加新数据
    ofstream fout(file,
        ios_base::out | ios_base::app | ios_base::binary);
    // 注意：某些系统不接受 ios::binary 模式
    if (!fout.is_open())
    {
        cerr << "无法打开 " << file << " 文件进行输出：\n";
        exit(EXIT_FAILURE);
    }

    cout << "请输入行星名称（输入空行退出）：\n";
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0')
    {
        eatline();
        cout << "请输入行星人口：";
        cin >> pl.population;
        // 检查输入是否失败（例如，输入了文本而不是数字）
        while (cin.fail())
        {
            cin.clear(); // 清除错误状态
            eatline();   // 清空错误的输入行
            cout << "输入无效。请输入一个数字：";
            cin >> pl.population;
        }
        eatline(); // 使用 eatline() 消耗掉 cin >> population 后留下的换行符

        cout << "请输入行星的重力加速度：";
        cin >> pl.g;
        // 同样为重力输入添加检查
        while (cin.fail())
        {
            cin.clear();
            eatline();
            cout << "输入无效。请输入一个数字：";
            cin >> pl.g;
        }
        eatline(); // 使用 eatline() 消耗掉 cin >> g 后留下的换行符

        fout.write((char*)&pl, sizeof pl);
        cout << "请输入行星名称（输入空行退出）：\n";
        cin.get(pl.name, 20);
    }
    fout.close();

    // 显示修改后的文件
    fin.clear(); // 对某些实现不是必需的，但加上也无害
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << "以下是 " << file << " 文件的新内容：\n";
        while (fin.read((char*)&pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ":"
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    cout << "完成。\n";
    return 0;
}