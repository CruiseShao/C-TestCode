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
        cout<<"��Ҫ���ڸ��˹���C++�Ĳ��԰���ʹ��,��ѡ����Ҫ���Եĺ�����"<<endl;
        cout<<"1������std::cin��ʹ�����ƣ�"<<endl;
        cout<<"2������std::cin.getline()��ʹ�ã�"<<endl;
        cout<<"3�����ں���ָ���ʹ�ã�"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"��Ҫ���Ե�case�ǣ�"<<endl;
        /*����������get��Ŀ�ľ��ǰ��������еĻس���ȥ����
        ��ֹ֮���ֶ��Ӻ�������������Ӱ�죬Ѫ�Ľ�ѵѽ*/
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
            cout<<"�����ѡ�����!"<<endl;
            break;
        }
        cout<<"��Ҫ�Ƿ�Ҫ�������ԣ�1���ظ����ֲ��ԣ�2���������ԣ�3���˳�����"<<endl;
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

void cinTest()//����std::cin��ʹ������
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"cin������κ�ǰ����ɫ�ո��ַ�(�ո��Ʊ�����з�)"<<endl;
    cout<<"cin��������ɫ�ո��ʱ��ֹͣ��ȡ������cin�����������Ƕ��ո���ַ���"<<endl;
    cout<<"��1����������:�ەF껣����뻧����:�㽭"<<endl;
    cout<<"��1����������:   �� �F껣����뻧����:�㽭"<<endl;
    cout<<"------------------------------------------------"<<endl;
    string name,city; 
    cout<<"����������֣�"<<endl;
    cin>>name;
    cout<<"������Ļ����أ�"<<endl;
    cin>>city;
    cout<<"�������Ϊ:"<<"\n"<<name<<endl;
    cout<<"��Ļ�����Ϊ:"<<"\n"<<city<<endl;
    return;
}
void getlineTest()//����std::cin.getline()��ʹ��
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"getline������κ�ǰ����ɫ�ո��ַ�(�ո��Ʊ��)"<<endl;
    cout<<"���������з�ʱ��ֹͣ��ȡ���˷���cin��ȱ��"<<endl;
    cout<<"cin.getline()����istream������getline()����string�����ǲ�һ������������������"<<endl;
    cout<<"��һ��������鸳ֵ�����أ�"<<endl;
    cout<<"istream& getline (char* s, streamsize n );"<<endl;
    cout<<"istream& getline (char* s, streamsize n, char delim );"<<endl;
    cout<<"���ã���istream�ж�ȡ����n���ַ�(����������Ƿ�)������s��Ӧ�������С���ʹ��û����n���ַ�,�������delim �������ﵽ���ƣ����ȡ��ֹ��delim�����ᱻ�����s��Ӧ�������С�"<<endl;
    cout<<"ע����ʹ��delim�󣬱���ҲҪ��\\n����������ȥ������Ȼ�������һ������ֱ����ֹ������"<<endl;
    cout<<"�ڶ������string���͵����أ�"<<endl;
    cout<<"istream& getline (istream&  is, string& str, char delim);"<<endl;
    cout<<"istream& getline (istream&& is, string& str, char delim);"<<endl;
    cout<<"istream& getline (istream&  is, string& str);"<<endl;
    cout<<"istream& getline (istream&& is, string& str);"<<endl;
    cout<<"�÷����ϵ�һ�����ƣ����Ƕ�ȡ��istream����Ϊ����is���������ġ���ȡ���ַ���������string���͵�str�С�"<<endl;
    cout<<"��1����������:�ەF�#�����뻧����:�㽭"<<endl;
    cout<<"��1����������:   �� �F�#�����뻧����:�㽭"<<endl;
    cout<<"------------------------------------------------"<<endl;
    string name,city; 
    cout<<"����������֣�"<<endl;
    getline(cin,name,'#');//����ֻ���õ����Ŵ����ַ���˫�������ַ������ᱨ������
    cin.get();//ȥ���������е�"\n"
    cout<<"������Ļ����أ�"<<endl;
    getline(cin,city);
    cout<<"�������Ϊ:"<<"\n"<<name<<endl;
    cout<<"��Ļ�����Ϊ:"<<"\n"<<city<<endl;
    return;
}
void funPointTest(void f1(),void f2(),void f3())
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"����ָ���ʹ��:"<<endl;
    cout<<"����ڳ����ж�����һ����������ô�ڱ���ʱϵͳ�ͻ�Ϊ��������������һ�δ洢�ռ䣬��δ洢�ռ���׵�ַ��Ϊ��������ĵ�ַ��"<<endl;
    cout<<"���Һ�������ʾ�ľ��������ַ����Ȼ�ǵ�ַ���ǾͿ��Զ���һ��ָ���������ţ����ָ������ͽ�������ָ���������ƺ���ָ�롣"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"��һ��:����ָ��洢���������൱�ڱ���"<<endl;
    cout<<"������һ��ָ�����po,��ָ���������ָ�򷵻�ֵ����Ϊvoid�ͣ�������������ĺ�����p������Ϊvoid(*)()��"<<endl;
    cout<<"f2����Ϊһ������ָ�룬����ֱ�Ӹ�ֵ����"<<endl;
    typedef void (*fundef)();//��������typedef��ָ����������Ĳ���
    //void (*po)()=f2;
    fundef po=f2;
    po();//ֱ��ִ�У��൱��f2()
    cout<<"�ڶ���:����ָ������洢�������ָ��"<<endl;
    void (*pa[3])()={f1,f2,f3};//f1,f2,f3ʵ�ʾ�����������ָ��
    pa[0]();//��һ��ִ�з�����C�����й涨������ô��
    (*pa[0])();//�ڶ���ִ�з���
    cout<<"������:����auto����ָ������"<<endl;
    void (**pb)()=pa;//auto pb=pa;
    pb[1]();//��һ��ִ�з���
    (*pb[1])();//�ڶ���ִ�з���
    cout<<"������:���ö���ָ�����洢����ָ�������ͷָ��"<<endl;
    cout<<"ע��Ϊ���ö���ָ�룺����ָ���޷�ʹ��++��--,Ҳ�޷�ֱ����һ��ָ��ͨ����������ͷָ����"<<endl;
    auto pc=&pa;//void (*(*pc)[3])()=&pa;
    (*pc)[2]();//��ȡֵ�ҵ�pa,֮��ͺ�pa��ʹ������
    (*(*pc)[2])();
    //void(*pd)()=pa[0];//void(*pd)()=pa�Ǵ�������,�ᱨ��
    //pd[0]();//���Ǵ���������pd[0]()��pd[1]()��pd[2]()�����ָ��f1
    return;
}
void f1()
{
    cout<<"���Ǻ���f1"<<endl;
    return;
}
void f2()
{
    cout<<"���Ǻ���f2"<<endl;
    return;
}
void f3()
{
    cout<<"���Ǻ���f3"<<endl;
    return;
}
