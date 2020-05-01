#include<iostream>
#include <string>
using namespace std;
void cinTest();
void getlineTest();
void funPointTest(void f1(),void f2(),void f3());void f1();void f2();void f3();
int main()
{ 
    char inChar;
    unsigned int choose;
    while(1)
    {  
        cout<<"------------------------------------------------"<<endl;
        cout<<"主要用于个人关于C++的测试案例使用,请选择你要测试的函数："<<endl;
        cout<<"1、关于std::cin的使用限制；"<<endl;
        cout<<"2、关于std::cin.getline()的使用；"<<endl;
        cout<<"3、关于函数指针的使用；"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"您要测试的case是："<<endl;
        /*这里用两个get的目的就是把输入流中的回车键去掉，
        防止之后又对子函数的输入重生影响，血的教训呀*/
        cin.get(inChar).get();
StartCase:
        choose=inChar-48;//'0'
        system("cls");
        switch (choose)
        {
        case 1:
            cinTest();
            break;
        case 2:
            getlineTest();
            break;
        case 3:
            funPointTest(f1,f2,f3);
            break;
        default:
            cout<<"输入的选项不存在!"<<endl;
            break;
        }
        cout<<"您要是否要继续测试（1：重复该轮测试，2：其他测试，3：退出）："<<endl;
        cin>>choose;
        if(choose==1)
            goto StartCase;
        else if(choose==2)
            continue;
        else
            break;
    }
    return 0;
}

void cinTest()//关于std::cin的使用限制
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"cin会忽略任何前导白色空格字符(空格、制表符或换行符)"<<endl;
    cout<<"cin在遇到白色空格符时会停止获取，所以cin不能输入包含嵌入空格的字符串"<<endl;
    cout<<"例1：输入姓名:邵旻昊，输入户籍地:浙江"<<endl;
    cout<<"例1：输入姓名:   邵 旻昊，输入户籍地:浙江"<<endl;
    cout<<"------------------------------------------------"<<endl;
    string name,city; 
    cout<<"输入你的名字："<<endl;
    cin>>name;
    cout<<"输入你的户籍地："<<endl;
    cin>>city;
    cout<<"你的名字为:"<<"\n"<<name<<endl;
    cout<<"你的户籍地为:"<<"\n"<<city<<endl;
    return;
}
void getlineTest()//关于std::cin.getline()的使用
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"getline会包括任何前导白色空格字符(空格、制表符)"<<endl;
    cout<<"在遇到换行符时会停止获取，克服了cin的缺点"<<endl;
    cout<<"cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数！！！"<<endl;
    cout<<"第一类关于数组赋值的重载："<<endl;
    cout<<"istream& getline (char* s, streamsize n );"<<endl;
    cout<<"istream& getline (char* s, streamsize n, char delim );"<<endl;
    cout<<"作用：从istream中读取至多n个字符(包含结束标记符)保存在s对应的数组中。即使还没读够n个字符,如果遇到delim 或字数达到限制，则读取终止，delim都不会被保存进s对应的数组中。"<<endl;
    cout<<"注意在使用delim后，必须也要将\\n从输入流中去除，不然会出现下一次输入直接终止的问题"<<endl;
    cout<<"第二类关于string类型的重载："<<endl;
    cout<<"istream& getline (istream&  is, string& str, char delim);"<<endl;
    cout<<"istream& getline (istream&& is, string& str, char delim);"<<endl;
    cout<<"istream& getline (istream&  is, string& str);"<<endl;
    cout<<"istream& getline (istream&& is, string& str);"<<endl;
    cout<<"用法和上第一种类似，但是读取的istream是作为参数is传进函数的。读取的字符串保存在string类型的str中。"<<endl;
    cout<<"例1：输入姓名:邵旻昊#，输入户籍地:浙江"<<endl;
    cout<<"例1：输入姓名:   邵 旻昊#，输入户籍地:浙江"<<endl;
    cout<<"------------------------------------------------"<<endl;
    string name,city; 
    cout<<"输入你的名字："<<endl;
    getline(cin,name,'#');//这里只能用单引号代表字符，双引号是字符串，会报错！！！
    cin.get();//去除输入流中的"\n"
    cout<<"输入你的户籍地："<<endl;
    getline(cin,city);
    cout<<"你的名字为:"<<"\n"<<name<<endl;
    cout<<"你的户籍地为:"<<"\n"<<city<<endl;
    return;
}
void funPointTest(void f1(),void f2(),void f3())
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"函数指针的使用:"<<endl;
    cout<<"如果在程序中定义了一个函数，那么在编译时系统就会为这个函数代码分配一段存储空间，这段存储空间的首地址称为这个函数的地址。"<<endl;
    cout<<"而且函数名表示的就是这个地址。既然是地址我们就可以定义一个指针变量来存放，这个指针变量就叫作函数指针变量，简称函数指针。"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"第一种:利用指针存储函数，即相当于别名"<<endl;
    cout<<"定义了一个指针变量po,该指针变量可以指向返回值类型为void型，且无输入参数的函数。p的类型为void(*)()。"<<endl;
    cout<<"f2本身为一个函数指针，所以直接赋值就行"<<endl;
    typedef void (*fundef)();//这是利用typedef简化指针变量创建的操作
    //void (*po)()=f2;
    fundef po=f2;
    po();//直接执行，相当于f2()
    cout<<"第二种:利用指针数组存储多个函数指针"<<endl;
    void (*pa[3])()={f1,f2,f3};//f1,f2,f3实际就是三个函数指针
    pa[0]();//第一种执行方法，C语言中规定可以这么做
    (*pa[0])();//第二种执行方法
    cout<<"第三种:利用auto函数指针数组"<<endl;
    void (**pb)()=pa;//auto pb=pa;
    pb[1]();//第一种执行方法
    (*pb[1])();//第二种执行方法
    cout<<"第三种:利用二级指针来存储三个指针数组的头指针"<<endl;
    cout<<"注意为何用二级指针：函数指针无法使用++和--,也无法直接用一级指针通过复制数组头指针解决"<<endl;
    auto pc=&pa;//void (*(*pc)[3])()=&pa;
    (*pc)[2]();//先取值找到pa,之后就和pa的使用类似
    (*(*pc)[2])();
    //void(*pd)()=pa[0];//void(*pd)()=pa是错误用例,会报错
    //pd[0]();//这是错误用例，pd[0]()、pd[1]()和pd[2]()结果都指向f1
    return;
}
void f1()
{
    cout<<"这是函数f1"<<endl;
    return;
}
void f2()
{
    cout<<"这是函数f2"<<endl;
    return;
}
void f3()
{
    cout<<"这是函数f3"<<endl;
    return;
}
