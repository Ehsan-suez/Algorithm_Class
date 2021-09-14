#include<iostream>
using namespace std;

///I/O
#define input()             freopen("D:/untitled_folder/algo/sample1k.fastq","r",stdin)
#define output()            freopen("D:/untitled_folder/algo/out0.txt","w",stdout)


///----------------------Main Code-------------------------------------///

 int quick_sort_help(string Nucleic_acid[],int left, int right)
    {
        string val = Nucleic_acid[right];
        string temp;

        int j = right;
        int i = left - 1;

        while (true)
        {
            //while(compare_less_than(Nucleic_acid[++i],val));
            while (Nucleic_acid[++i] < val);

            while (Nucleic_acid[--j] > val) {
           // while(compare_less_than(Nucleic_acid[j--],val)) {
                if(j == left)
                    break;
            }

            if(i >= j)
                break;

            temp=Nucleic_acid[i];
            Nucleic_acid[i]=Nucleic_acid[j];
            Nucleic_acid[j]=temp;
        }

        temp=Nucleic_acid[i];
        Nucleic_acid[i]=Nucleic_acid[right];
        Nucleic_acid[right]=temp;

        return i;
    }

    void quicksort(string Nucleic_acid[],int left, int right)
    {
        if (left < right)
        {
            int pivot = quick_sort_help(Nucleic_acid, left, right);
            quicksort(Nucleic_acid, left, pivot - 1);
            quicksort(Nucleic_acid, pivot + 1, right);
        }
    }

    void quick_sort(string Nucleic_acid[],int size){
        quicksort(Nucleic_acid,0,size-1);
    }


int main()
{

  input();
 // output();

    int n, i=0,j=0;
    string s[100000],s1;
    //quick_sort(s,n);

    while(cin>>s1)
    {
        j++;
        if(j==3)
            s[i++]=s1;
        else if((j-3)%5==0)
            s[i++]=s1;

    }
    n=i;
    // To show the unsorted indexed sequence, use the following two lines
    //for(int i=0;i<n;i++)
    // cout<<s[i]<<endl;
    //cout<<"---------------"<<endl;
    quick_sort(s,n);
    for(int j=0;j<n;j++)
    cout<<s[j]<<endl;
    return 0;
}
