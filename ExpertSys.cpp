#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class HosMedExp
{
private:
    string patient_name, another_sym, dis, diabetes_sym, hyper_sym;
    int age, sym_no, cnt;
    const int threshold_val = 3;

public:
    HosMedExp()
    {
        cnt = 0;
    }

    void personal_details_input()
    {
        cout << "Enter Patient's Name: ";
        cin >> patient_name;
        cout << "Enter Patient's Age: ";
        cin >> age; 
    }

    void med_input()
    {
        cout << "Various Symptoms list is given below: \n";
        cout << "1.Cough\n2.Itchiness\n3.Headache\n";
        cout << "Enter the number of symptoms you have from the given list: ";
        cin >> sym_no;
        cout << "Are you feeling any other symptoms also? [Enter yes/no]: ";
        cin >> another_sym;

        string opt = another_sym;
        transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

        if (opt == "no")
        {
            if (sym_no == 1)
            {
                cout << "Medicine: Cofsils Orange Lozenges Strip Of 10\n";
            }
            else if (sym_no == 2)
            {
                cout << "Medicine: Aspirin\n";
            }
            else
            {
                cout << "Medicine: Acetaminophen\n";
            }
        }
        else
        {
            cout << "Describe your symptoms: (fever,sore throat, runny/stuffy nose, muscle/body aches, headache )\n";
            cin.ignore();
            getline(cin, dis); // Get the entire line of symptoms description

            // Convert the input to lowercase for easier comparison
            transform(dis.begin(), dis.end(), dis.begin(), ::tolower);

            // Check for symptoms mentioned in the input sentence
            cnt = 0;
            if (dis.find("fever") != string::npos)
            {
                cnt++;
            }
            if (dis.find("sore throat") != string::npos)
            {
                cnt++;
            }
            if (dis.find("runny/stuffy nose") != string::npos)
            {
                cnt++;
            }
            if (dis.find("muscle/body aches") != string::npos)
            {
                cnt++;
            }
            if (dis.find("headache") != string::npos)
            {
                cnt++;
            }

            // Check for the threshold value
            if (cnt >= threshold_val)
            {
                cout << "\n\nYou Have Influenza (Flu). The Treatment is: Rest, hydration, over-the-counter pain relievers (such as ibuprofen or acetaminophen) to reduce fever and relieve symptoms. In some cases, antiviral medications like oseltamivir (Tamiflu) may be prescribed if started early in the course of the illness.\n\n";
            }
            else
            {
                cout << "\nOk. Take the tablet 'Aspirin'.\n\n";
            }
        }
    }

    void diabetes_check()
    {
        cout << "Do you have symptoms like increased thirst, frequest urination, fatigue, blurred vision, unexplained weight loss? [Yes/No]\n";
        cin >> diabetes_sym;
        string opt1 = diabetes_sym;
        transform(opt1.begin(), opt1.end(), opt1.begin(), ::tolower);
        if (opt1 == "no")
        {
            cout << "No worries!!\n";
        }
        else
        {
            cout << "Describe your symptoms related to Diabetes: (increased thirst, frequest urination, fatigue, blurred vision, unexplained weight loss)\n";
            cin.ignore();
            getline(cin, dis); // Get the entire line of symptoms description

            // Convert the input to lowercase for easier comparison
            transform(dis.begin(), dis.end(), dis.begin(), ::tolower);

            // Check for symptoms mentioned in the input sentence
            cnt = 0;
            if (dis.find("increased thirst") != string::npos)
            {
                cnt++;
            }
            if (dis.find("frequent urination") != string::npos)
            {
                cnt++;
            }
            if (dis.find("unexplained weight loss") != string::npos)
            {
                cnt++;
            }
            if (dis.find("fatigue") != string::npos)
            {
                cnt++;
            }
            if (dis.find("blurred vision") != string::npos)
            {
                cnt++;
            }

            // Check for the threshold value
            if (cnt >= threshold_val)
            {
                cout << "You Have Type 2 Diabetes. The Treatment: Lifestyle changes including diet modification and exercise, oral medications such as metformin to lower blood sugar levels, insulin injections in some cases, regular monitoring of blood sugar levels.\n";
            }
            else
            {
                cout << "Ok. Take the tablet 'Metformin'.\n";
            }
        }
    }

    void hypertension_check()
    {
        cout << "\n\nDo you have symptoms like shortness of breath, nosebleeds,dizziness? [Yes/No]\n";
        cin >> hyper_sym;
        string opt2 = hyper_sym;
        transform(opt2.begin(), opt2.end(), opt2.begin(), ::tolower);
        if (opt2 == "no")
        {
            cout << "No worries!!\n\n";
        }
        else
        {
            cout << "\n\n Describe your symptoms related to Hypertension: (shortness of breath, nosebleeds, dizziness) \n";
            cin.ignore();
            getline(cin, dis); // Get the entire line of symptoms description

            // Convert the input to lowercase for easier comparison
            transform(dis.begin(), dis.end(), dis.begin(), ::tolower);

            // Check for symptoms mentioned in the input sentence
            cnt = 0;
            if (dis.find("shortness of breath") != string::npos)
            {
                cnt++;
            }
            if (dis.find("nosebleeds") != string::npos)
            {
                cnt++;
            }
            if (dis.find("dizziness") != string::npos)
            {
                cnt++;
            }

            // Check for the threshold value
            if (cnt >= (threshold_val - 1))
            {
                cout << "\nYou Have Hypertension (High Blood Pressure). The Treatment is: Lifestyle changes including a low-sodium diet, regular exercise, weight loss if overweight, medication such as ACE inhibitors, beta-blockers, calcium channel blockers, or diuretics to lower blood pressure.\n";
            }
            else
            {
                cout << "\nOk. Take the tablet 'Triptans'.\n";
            }
        }
    }
};

int main()
{
    HosMedExp h1;
    h1.personal_details_input();
    h1.med_input();
    h1.diabetes_check();
    h1.hypertension_check();
    cout << "Don't worry!! Continue taking above medicines and precautions .. you will be fine :)!! THANK YOU";
    return 0;
}