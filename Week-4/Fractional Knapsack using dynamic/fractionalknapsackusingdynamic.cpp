#include <bits/stdc++.h>
using namespace std;

class obj
{
public:
    int weight;
    int profits;
};

bool cmp(obj a, obj b)
{
    double r1 = (double)a.profits / (double)a.weight;
    double r2 = (double)b.profits / (double)b.weight;
    return r1 > r2;
}

double knapsack_greedy(int max_weight, vector<obj> list, int num)
{
    /*for(int i=1;i<=num;i++){
        cout << list[i].value << list[i].weight << endl;
    }
    cout << endl;*/
    sort(list.begin(), list.end(), cmp);
    // for(int i=0;i<num;i++){
    //     cout<<list[i].weight<<"/"<<list[i].profits<<"\t\t\t"<<"\n";
    // }
    double pweight = 0, pval = 0;
    int i;
    for (i = 0; i < num; i++)
    {
        if (pweight + list[i].weight <= max_weight)
        {
            pweight += list[i].weight;
            pval += list[i].profits;
            cout << list[i].weight << "/" << list[i].profits << "\t\t\t" << 1 << "\n";
        }
        else
        {
            int frac_weight = max_weight - pweight;
            pweight = max_weight;
            pval += ((double)frac_weight / (double)list[i].weight) * list[i].profits;
            cout << list[i].weight << "/" << list[i].profits << "\t\t\t" << (double)frac_weight / (double)list[i].weight << "\n";
            break;
        }
    }

    for (int j = i + 1; j < num; j++)
    {
        cout << list[j].weight << "/" << list[j].profits << "\t\t\t" << 0 << "\n";
    }

    return pval;
}

void knapsack(int max_weight, obj list[], int num)
{
    int B[num + 1][max_weight + 1];
    for (int i = 0; i <= num; i++)
    {
        for (int w = 0; w <= max_weight; w++)
        {
            if (i == 0 || w == 0)
            {
                B[i][w] = 0;
            }
            else if (list[i - 1].weight <= w)
            {
                if (list[i - 1].profits + B[i - 1][w - list[i - 1].weight] > B[i - 1][w])
                    B[i][w] = list[i - 1].profits + B[i - 1][w - list[i - 1].weight];
                else
                    B[i][w] = B[i - 1][w];
            }
            else
                B[i][w] = B[i - 1][w];
        }
    }
    // return B[num][max_weight];
    int max_value = B[num][max_weight];
    double maxi = max_value;
    cout << "Maximum Value : " << max_value << endl;
    cout << "ObjectsChosen/Profits\tFractionChosen: \n";
    int solution_set[num];
    for (int i = num; i > 0; i--)
    {
        if (max_value > 0)
        {
            if (max_value != B[i - 1][max_weight])
            {
                // cout << i << " ";
                cout << list[i - 1].weight << "/" << list[i - 1].profits << "\t\t\t" << 1 << "\n";
                max_value -= list[i - 1].profits;
                max_weight -= list[i - 1].weight;
                solution_set[i - 1] = 1;
            }
            else
            {
                solution_set[i - 1] = 0;
            }
        }
        else
        {
            solution_set[i - 1] = 0;
        }
    }

    vector<obj> a;
    for (int i = 0; i < num; i++)
    {
        // cout<<solution_set[i]<<" ";
        if (solution_set[i] == 0)
        {
            a.push_back(list[i]);
        }
    }

    double from_greedy = knapsack_greedy(max_weight, a, a.size());
    cout << "Maximum value : " << double(from_greedy + maxi);
}

void randgen(obj list[], int num, int mweight)
{
    cout << "Weights Profits : \n";
    for (int i = 0; i < num; i++)
    {
        list[i].profits = (rand() % 300) + 1;
        list[i].weight = (rand() % mweight) + 1;
        cout << list[i].weight << " " << list[i].profits << "\t";
    }
    cout << endl;
}

int main()
{
    int num;
    cout << "Enter the number of objects: ";
    cin >> num;
    int val, weight;
    obj list[num];
    int mweight;
    cout << "Enter the maximum weight : ";
    cin >> mweight;
    randgen(list, num, mweight);
    knapsack(mweight, list, num);
}