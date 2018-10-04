#include<iostream>
#include<vector>
using namespace std;
long totalcombs(int n, int r)

{

    long c = 1;

    if (r > n)

        return 0;

    for (long d = 1; d <= r; d++)

    {

        c *= n--;

        c /= d;

    }

    return c;

}



// example code to get all combination

int main()

{

    vector<int> data;



    string input("ABC");



    int n = 3;

    int j = 1;

    int k = 3;



    for (int dataNum = j; dataNum <= k; dataNum++)

    {

        int r = dataNum;

        int total = totalcombs(n, r);

        int ccount = 1;

        bool done = true;

        for (int inputNum = 0; inputNum < r; inputNum++)

            data.push_back(inputNum);

        while (done)

        {

            done = false;

            cout << ccount++ << " of " << total << " ";

            for (int outputNum = 0; outputNum < r; outputNum++)

            {

                cout << input[data[outputNum]] << " ";

            }

            cout << endl;

            for (int inputNum = r - 1; inputNum >= 0; inputNum--)

            {

                if (data[inputNum] <= (n - 1) - (r - inputNum))

                {

                    data[inputNum]++;

                    for (int stringNum = inputNum + 1; stringNum < r; stringNum++)

                    {

                        data[stringNum] = data[stringNum - 1] + 1;

                    }

                    inputNum = -1;

                    done = true;

                }

            }

        }

        data.clear();

    }

    return 0;
    }
