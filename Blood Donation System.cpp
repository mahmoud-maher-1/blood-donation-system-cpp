#include <bits\stdc++.h>
#include <windows.h>

using namespace std;

namespace Objects {
    // DATE IN YY/MM/DD
    class Date {
    private:
        string FORMAT = "%Y-%m-%d";
        string _day;
        string _month;
        string _year;
        chrono::year_month_day _date;
        chrono::system_clock::time_point _timeSaved;

        pair<int, pair<int, pair<int, int>>> getYearMonth(chrono::system_clock::time_point t1, chrono::system_clock::time_point t2) {
            chrono::year_month_day t0 = chrono::floor<chrono::days>(t1), t = chrono::floor<chrono::days>(t2);
            return {(int)t0.year(), {(int)t.year(), {(unsigned int)t0.month(), (unsigned int)t.month()} } };
        }

    public:
        Date() {
            this->_timeSaved = chrono::system_clock::now();
            this->_date = chrono::floor<chrono::days>(this->_timeSaved);
            unsigned int day = (unsigned int)this->_date.day(), month = (unsigned int)this->_date.month();
            this->_day = ((day < 10) ? "0" + to_string(day) : to_string(day));
            this->_month = ((month < 10) ? "0" + to_string(month) : to_string(month));
            this->_year = to_string((int)this->_date.year());
        }

        Date(chrono::system_clock::time_point t) {
            this->_timeSaved = t;
            this->_date = chrono::floor<chrono::days>(this->_timeSaved);
            unsigned int day = (unsigned int)this->_date.day(), month = (unsigned int)this->_date.month();
            this->_day = ((day < 10) ? "0" + to_string(day) : to_string(day));
            this->_month = ((month < 10) ? "0" + to_string(month) : to_string(month));
            this->_year = to_string((int)this->_date.year());
        }

        Date(string d) {
            stringstream ss(d);
            tm time;

            ss >> get_time(&time, FORMAT.c_str());
            Date(chrono::system_clock::from_time_t(mktime(&time)));
        }

        chrono::year_month_day getDate() {
            return this->_date;
        }

        string day() {
            return this->_day;
        }

        string month() {
            return this->_month;
        }

        string year() {
            return this->_year;
        }

        chrono::system_clock::time_point timeSaved() {
            return this->_timeSaved;
        }

        bool isEligible(chrono::system_clock::time_point _time) {
            auto result = this->getYearMonth(this->_timeSaved, _time);
            if ((result.second.first - result.first) * 12 - (result.second.second.second - result.second.second.first) >= 3) {
                return true;
            }

            return false;
        }

        bool operator==(const Date& dat) {
            return (this->_day == dat._day && this->_month == dat._month && this->_year == dat._year);
        }

        friend ostream& operator<<(ostream& out, const Date& dat) {
            out << dat._year << '-' << dat._month << '-' << dat._day;
            return out;
        }
    };

    class Donor{
    private:
        int _ID;
        string _Name;
        string _Mail;
        string _Password;
        int _Age;
        char _Gender;
        string _Bloodtype;
        vector<string> _Diseases;
        vector<string> _Medicines;
        Date _lastDonationDate;

    public:
        Donor() {}
        Donor(int ID, string Name, string Mail, string Password, int Age, char Gender, string Bloodtype, vector<string> Diseases, vector<string> Medicines, Date lastDonationDate) {
            this->_ID = ID;
            this->_Name = Name;
            this->_Mail = Mail;
            this->_Password = Password;
            this->_Age = Age;
            this->_Gender = Gender;
            this->_Bloodtype = Bloodtype;
            this->_Diseases = Diseases;
            this->_Medicines = Medicines;
            this->_lastDonationDate = lastDonationDate;
        }

        int ID() {
            return this->_ID;
        }

        string Name() {
            return this->_Name;
        }

        string Mail() {
            return this->_Mail;
        }

        string Password() {
            return this->_Password;
        }

        int Age() {
            return this->_Age;
        }

        char Gender() {
            return this->_Gender;
        }

        string Bloodtype() {
            return this->_Bloodtype;
        }

        vector<string> Diseases() {
            return this->_Diseases;
        }

        vector<string> Medicines() {
            return this->_Medicines;
        }

        Date lastDonationDate() {
            return this->_lastDonationDate;
        }

        bool operator==(const Donor& don) {
            return (this->_ID == don._ID && this->_Name == don._Name && this->_Mail == don._Mail && this->_Password == don._Password && this->_Bloodtype == don._Bloodtype && this->_Diseases.size() == don._Diseases.size() && this->_Medicines.size() == don._Medicines.size() && this->_lastDonationDate == don._lastDonationDate);
        }

        friend ostream& operator<<(ostream& out, Donor don) {
            out << "ID: " << don._ID << endl;
            out << "Name: " << don._Name << endl;
            out << "Email: " << don._Mail << endl;
            out << "Age: " << don._Age << endl;
            out << "Blood type: " << don._Bloodtype << endl;
            out << "Current diseases: ";
            if (!don._Diseases.empty()) {
                for (const auto& i : don._Diseases) {
                    out << i << " ";
                }
                out << endl;
            } else {
                out << "None" << endl;
            }

            out << "Current medicines: ";
            if (!don._Medicines.empty()) {
                for (const auto& i : don._Medicines) {
                    out << i << " ";
                }
                out << endl;
            } else {
                out << "None" << endl;
            }
            out << "Last donation date: " << don._lastDonationDate << endl;
            out << "Is eligible for another donation now: " << ((don._lastDonationDate.isEligible(Date().timeSaved())) ? "Yes" : "No") << endl;

            return out;
        }
    };

    class Recipient {
    private:
        int _ID;
        string _Name;
        string _Mail;
        string _Password;
        int _Age;
        char _Gender;
        string _Bloodtype;
        string _Hospital;
        string _DoctorOfCase;

    public:
        Recipient() {}
        Recipient(int ID, string Name, string Mail, string Password, int Age, char Gender, string Bloodtype, string Hospital, string DoctorOfCase) {
            this->_ID = ID;
            this->_Name = Name;
            this->_Mail = Mail;
            this->_Password = Password;
            this->_Age = Age;
            this->_Gender = Gender;
            this->_Bloodtype = Bloodtype;
            this->_Hospital = Hospital;
            this->_DoctorOfCase = DoctorOfCase;
        }

        int ID() {
            return this->_ID;
        }

        string Name() {
            return this->_Name;
        }

        string Mail() {
            return this->_Mail;
        }

        string Password() {
            return this->_Password;
        }

        int Age() {
            return this->_Age;
        }

        char Gender() {
            return this->_Gender;
        }

        string Bloodtype() {
            return this->_Bloodtype;
        }

        string Hospital() {
            return this->_Hospital;
        }

        string DoctorOfCase() {
            return this->_DoctorOfCase;
        }

        bool operator==(const Recipient& rec) {
            return (this->_ID == rec._ID && this->_Name == rec._Name && this->_Mail == rec._Mail && this->_Password == rec._Password && this->_Age == rec._Age && this->_Gender == rec._Gender && this->_Bloodtype == rec._Bloodtype && this->_Hospital == rec._Hospital && this->_DoctorOfCase == rec._DoctorOfCase);
        }
    };

    //date for date_of_request
    class DonationRequest {
    private:
        Date _date;
        string _Bloodtype;
        int _quantity;
    public:
        DonationRequest(Date date, string Bloodtype, int quantity) {
            this->_date = date;
            this->_Bloodtype = Bloodtype;
            this->_quantity = quantity;
        }

        Date date() {
            return this->_date;
        }

        string Bloodtype() {
            return this->_Bloodtype;
        }

        int quantity() {
            return this->_quantity;
        }
    };

    //date for date_of_blood_request
    class BloodRequest : public DonationRequest {
    public:
        BloodRequest(Date date, string Bloodtype, int quantity) : DonationRequest(date, Bloodtype, quantity) {}
    };

    //date for date_received and isExpired
    class AvailableBlood : public DonationRequest {
    private:
        bool _isExpired;

        bool checkExpiry(Date dat) {
            Date now = Date();

            if (((stoi(now.year()) - stoi(dat.year())) * 12 * 30) + ((stoi(now.month()) - stoi(dat.month()) * 30) + (stoi(now.day()) - stoi(dat.day()))) > 42) {
                return false;
            }

            return true;
        }
    public:
        AvailableBlood(Date date, string Bloodtype, int quantity) : DonationRequest(date, Bloodtype, quantity), _isExpired(checkExpiry(date)) {}

        bool isExpired() {
            return this->_isExpired;
        }
    };

}

using namespace Objects;

namespace database {
    vector<Donor> donors;
    vector<Recipient> recipients;
    queue<DonationRequest> donationrequests;
    queue<BloodRequest> bloodrequests;
    queue<AvailableBlood> availablebloodtypes;
}

namespace FileHandler {
    using namespace database;

    const string donorsFile = "donors.txt";
    const string recipientsFile = "recipients.txt";
    const string donationRequestsFile = "donationrequests.txt";
    const string bloodrequestsFile = "bloodrequests.txt";
    const string AvailableBloodtypesFile = "availablebloodtypes.txt";

    Donor lineToDonor(string line) {
        int id, age, medsize, dissize;
        string name, mail, password, bloodtype;
        char gender;
        vector<string> diseases, medicines;
        Date lastdonationdate;

        stringstream ss(line);
        string word;

        ss >> word;
        id = stoi(word);

        ss >> name >> mail >> password >> word;
        age = stoi(word);

        ss >> word;
        gender = word[0];

        ss >> bloodtype;
        ss >> word;
        dissize = stoi(word);
        while (dissize--) {
            ss >> word;
            diseases.push_back(word);
        }

        ss >> word;
        medsize = stoi(word);
        while (medsize--) {
            ss >> word;
            medicines.push_back(word);
        }

        ss >> word;
        lastdonationdate = Date(word);

        return {id, name, mail, password, age, gender, bloodtype, diseases, medicines, lastdonationdate};
    }

    Recipient lineToRecipient(string line) {
        int id, age;
        string name, mail, password, bloodtype, hospital, doctorofcase, word;
        char gender;
        stringstream ss(line);

        ss >> word;
        id = stoi(word);

        ss >> name >> mail >> password >> word;
        age = stoi(word);

        ss >> word;
        gender = word[0];

        ss >> bloodtype >> hospital >> doctorofcase;

        return {id, name, mail, password, age, gender, bloodtype, hospital, doctorofcase};
    }

    //note: next 3 functions are identical, change will be looked for later
    DonationRequest lineToDR(string line) {
        string dat, bloodtype, quantity;
        stringstream ss(line);

        ss >> dat >> bloodtype >> quantity;

        return {{dat}, bloodtype, stoi(quantity)};
    }

    BloodRequest lineToBR(string line) {
        string dat, bloodtype, quantity;
        stringstream ss(line);

        ss >> dat >> bloodtype >> quantity;

        return {{dat}, bloodtype, stoi(quantity)};
    }

    AvailableBlood lineToAB(string line) {
        string dat, bloodtype, quantity;
        stringstream ss(line);

        ss >> dat >> bloodtype >> quantity;

        return {{dat}, bloodtype, stoi(quantity)};
    }

    fstream* file;

    void isopenfile(fstream* filestream, string filename) {
        if (!filestream->is_open())
            filestream->open(filename, ios::out | ios::in);
    }

    // load everything to our vectors and queues
    void loadEverything() {
        string line;
        if (file == nullptr)
            file = new fstream();
        // load donors;
        {
            file->open(donorsFile, ios::in);
            isopenfile(file, donorsFile);

            while (getline(*file, line)) {
                if (!line.empty())
                    donors.push_back(lineToDonor(line));
            }

            file->close();
            line.clear();
        }

        // load recipients;
        {
            file->open(recipientsFile, ios::in);
            isopenfile(file, recipientsFile);

            while (getline(*file, line)) {
                if (line.empty())
                    recipients.push_back(lineToRecipient(line));
            }

            file->close();
            line.clear();
        }

        // load donation requests
        {
            file->open(donationRequestsFile, ios::in);
            isopenfile(file, donationRequestsFile);

            while (getline(*file, line)) {
                donationrequests.push(lineToDR(line));
            }

            file->close();
            line.clear();
        }

        // load blood requests
        {
            file->open(bloodrequestsFile, ios::in);
            isopenfile(file, bloodrequestsFile);

            while (getline(*file, line)) {
                bloodrequests.push(lineToBR(line));
            }

            file->close();
            line.clear();
        }

        // load available bloodtypes
        {
            file->open(AvailableBloodtypesFile, ios::in);
            isopenfile(file, AvailableBloodtypesFile);

            while (getline(*file, line)) {
                availablebloodtypes.push(lineToAB(line));
            }

            file->close();
            line.clear();
        }
    }

    void saveDonor(Donor don) {
        if (file == nullptr) {
            file = new fstream();
        }

        file->open(donorsFile, ios::app);

        isopenfile(file, donorsFile);

        *file << don.ID() << ' ' << don.Name() << ' ' << don.Mail() << ' ' << don.Password() << ' ' << don.Age() << ' ' << don.Gender() << ' ' << don.Bloodtype() << ' ' << don.Diseases().size() << ' ';
        for (const auto& i : don.Diseases())
            *file << i << ' ';
        *file << don.Medicines().size() << ' ';
        for (const auto& i : don.Medicines())
            *file << i << ' ';
        *file << don.lastDonationDate().year() << '-' << don.lastDonationDate().month() << '-' << don.lastDonationDate().day() << endl;

        file->close();
    }

    void saveRecipient(Recipient rec) {
        if (file == nullptr) {
            file = new fstream();
        }

        file->open(recipientsFile, ios::app);

        isopenfile(file, recipientsFile);

        *file << rec.ID() << ' ' << rec.Name() << ' ' << rec.Mail() << ' ' << rec.Password() << ' ' << rec.Age() << ' ' << rec.Gender() << ' ' << rec.Bloodtype() << ' ' << rec.Hospital() << ' ' << rec.DoctorOfCase() << endl;

        file->close();
    }

    void saveBloodRequest(BloodRequest bloodRequest) {
        if (file == nullptr) {
            file = new fstream();
        }

        file->open(bloodrequestsFile, ios::app);

        isopenfile(file, bloodrequestsFile);

        *file << bloodRequest.date().year() << '-' << bloodRequest.date().month() << '-' << bloodRequest.date().year() << ' ' << bloodRequest.Bloodtype() << ' ' << bloodRequest.quantity() << endl;
    }

    void saveDonationRequest(DonationRequest donationRequest) {
        if (file == nullptr) {
            file = new fstream();
        }

        file->open(donationRequestsFile, ios::app);

        isopenfile(file, donationRequestsFile);

        *file << donationRequest.date().year() << '-' << donationRequest.date().month() << '-' << donationRequest.date().year() << ' ' << donationRequest.Bloodtype() << ' ' << donationRequest.quantity() << endl;
    }

    void saveAvailableBlood(AvailableBlood availableBlood) {
        if (file == nullptr) {
            file = new fstream();
        }

        file->open(AvailableBloodtypesFile, ios::app);

        isopenfile(file, AvailableBloodtypesFile);

        *file << availableBlood.date().year() << '-' << availableBlood.date().month() << '-' << availableBlood.date().year() << ' ' << availableBlood.Bloodtype() << ' ' << availableBlood.quantity() << endl;
    }

    void refreshEverything() {
        if (file == nullptr)
            file = new fstream();
        // refresh donors;
        {
            file->open(donorsFile, ios::trunc);

            for (const auto& i : donors) {
                saveDonor(i);
            }

            file->close();
        }

        // refresh recipients;
        {
            file->open(recipientsFile, ios::trunc);

            for (const auto& i : recipients) {
                saveRecipient(i);
            }

            file->close();
        }

        // refresh donation requests
        {
            file->open(donationRequestsFile, ios::trunc);
            auto copy = donationrequests;

            while (!copy.empty()) {
                saveDonationRequest(copy.front());
                copy.pop();
            }

            file->close();
        }

        // refresh blood requests
        {
            file->open(donorsFile, ios::trunc);

            auto copy = bloodrequests;

            while (!copy.empty()) {
                saveBloodRequest(copy.front());
                copy.pop();
            }

            file->close();
        }

        // refresh available bloodtypes
        {
            file->open(donorsFile, ios::trunc);

            auto copy = availablebloodtypes;

            while (!copy.empty()) {
                saveAvailableBlood(copy.front());
                copy.pop();
            }

            file->close();
        }
    }
}

namespace DriverCode {
    using namespace database;

    void start();
    void login();

    void pc() {
        system("pause > 0");
        system("cls");
    }

    void pc(string message) {
        message = "echo " + message;
        system(message.c_str());
        pc();
    }

    void pc(int i, string message) {
        while (i--)
            cout << endl;
        pc(message);
    }

    void c() {
        system("cls");
    }

    void donorSignup() {
        c();
        const string unacceptablediseases[] { "hepatitis", "fever", "htlv", "highbloodpressure", "cancer", "hemochromatosis", "heartdisease", "syphillis", "hemophilia" };
        const string unacceptablemedicine[] { "isotretinoin", "acitretin", "aubagio", "hiv", "antibiotics", "piroxicam", "avodart", "aspirin", "heparin"};

        cout << "Welcome to donor sign up page!\nPlease enter the following information carefully and accordingly!" << endl;
        int id, age;
        string name, mail, password, bloodtype, dis, med;
        char gender;
        vector<string> diseases, medicine;
        string (*lower)(string) = [](string s) -> string {
            for (auto &i : s) {
                if (int(i) < 97)
                    i += 32;
            }

            return s;
        };

        cout << "Please enter your name: ";
        cin >> name;

        cout << "Please enter your ID: ";
        cin >> id;

        cout << "Please enter your age: ";
        cin >> age;

        if (age < 17 || age > 60) {
            cout << "Sorry! you cannot register! Please come back when you're older...";
            pc(2, "Press any key to go back to main menu...");
            return;
        }

        cout << "Please enter your gender (F | M): ";
        cin >> gender;

        cout << "Please enter your blood type: ";
        cin >> bloodtype;

        cout << "Please enter you email: ";
        cin >> mail;

        cout << "Please enter your new password: ";
        cin >> password;


        cout << "If you have any diseases please let us know their names (no space, each name in a separate line until you enter 0). If you happen to have no diseases, please enter 0 : ";
        cin >> dis;

        while (dis != "0") {
            for (const auto& i : unacceptablediseases) {
                if (lower(dis) == i) {
                    cout << "We're sorry but we can't continue your registration due to your condition...";
                    pc(2, "Press any key to go back to main menu...");
                    return;
                }
            }

            diseases.push_back(dis);
            cin >> dis;
        }

        cout << "If you take any specific medications please let us know their names (no space, each name in a separate line until you enter 0). If you happen to take no medication, please enter 0 : ";
        cin >> med;

        while (med != "0") {
            for (const auto& i : unacceptablemedicine) {
                if (lower(med) == i) {
                    cout << "We're sorry but we can't continue your registration due to the medication you're following...";
                    pc(2, "Press any key to go back to main menu...");
                    return;
                }
            }

            medicine.push_back(med);
            cin >> med;
        }

        Donor result = {id, name, mail, password, age, gender, bloodtype, diseases, medicine, Date()};
        FileHandler::saveDonor(result);
        database::donors.push_back(result);
        cout << "Your donor account has been registered successfully!";
        pc(2, "Press any key to go back to main menu...");
        start();
    }

    void recipientSignup() {
        c();
        int id, age;
        string name, mail, password, bloodtype, hospital, doctorofcase;
        char gender;

        cout << "Please enter your name: ";
        cin >> name;

        cout << "Please enter your ID: ";
        cin >> id;

        cout << "Please enter your age: ";
        cin >> age;

        cout << "Please enter your gender (F | M): ";
        cin >> gender;

        cout << "Please enter your blood type: ";
        cin >> bloodtype;

        cout << "Please enter the name of the hospital you're in: ";
        cin >> hospital;

        cout << "Please enter the name of the doctor of case: ";
        cin >> doctorofcase;

        cout << "Please enter you email: ";
        cin >> mail;

        cout << "Please enter your new password: ";
        cin >> password;

        Recipient result = {id, name, mail, password, age, gender, bloodtype, hospital, doctorofcase};
        FileHandler::saveRecipient(result);
        database::recipients.push_back(result);
        cout << "Your recipient account has been registered successfully!";
        pc(2, "Press any key to go back to main menu...");
        start();
    }

    void signup() {
        c();
        int choice;

        cout << "1- Donor signup\n2- Recipient signup\n3- Go back to main menu\nYour choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                donorSignup();
                break;

            case 2:
                recipientSignup();
                break;

            case 3:
                start();
                break;

            default:
                cout << "Invalid choice! Please try again..." << endl;
                pc(1, "Press any button to go back..");
        }
        signup();
    }

    void donorPage(Donor don) {
        c();
        int choice;

        cout << "Hello, " <<  don.Name() << " !" << endl;
        cout << "What would you like to do today?" << endl;
        cout << "1- Update my data" << endl;
        cout << "2- Request Donation Appointment" << endl;
        cout << "3- Delete my account" << endl;
        cout << "4- Log out" << endl;
        cout << "Your choice: ";

        cin >> choice;

        switch(choice) {
            case 1: {
                // yet to be implemented.
            } break;

            case 2: {
                string date;

                cout << "Please enter the date you're going to donate your blood in: ";
                cin >> date;

                FileHandler::saveDonationRequest({Date(), don.Bloodtype(), 1});
                cout << "Appointment request sent successfully! An admin will check the request and reply as soon as possible..." << endl;
                pc(2, "Press any key to go back to main menu...");
            } break;

            case 3: {
                donors.erase(find(donors.begin(), donors.end(), don));
                FileHandler::refreshEverything();
                cout << "Account deleted successfully! You are no longer registered in our systems!" << endl;
                pc(2, "Press any key to go back to main menu...");
            } break;

            case 4:
                login();
                break;

            default:
                cout << "Invalid choice! Please try again";
                pc(2, "Press any key to restart...");
                donorPage(don);
                return;
        }
    }

    void recipientPage(Recipient rec) {
        c();
        int choice;

        cout << "Hello, " <<  rec.Name() << "!" << endl;
        cout << "What would you like to do today?" << endl;
        cout << "1- Update my data" << endl;
        cout << "2- Request Blood Delivery" << endl;
        cout << "3- Search for availability of blood type" << endl;
        cout << "4- Delete my account" << endl;
        cout << "5- Log out" << endl;
        cout << "Your choice: ";

        switch(choice) {
            case 1: { // NEEDS TO BE LOOKED AT LATER - recepientUpdateData
                int dataChoice;
                string tmpstr;

                cout << "What would you like to edit about your data?" << endl;
                cout << "1- Mail" << endl;
                cout << "2- Password" << endl;
                cout << "3- Hospital" << endl;
                cout << "4- Doctor Of case" << endl;
                cout << "Your choice: ";
                cin >> dataChoice;

                if (dataChoice > 4 || dataChoice < 1) {
                    cout << "Invalid choice! Please try again";
                    pc(2, "Press any key to restart...");
                    recipientPage(rec);
                    return;
                }

                cout << "Please enter the new data for what you chose: ";
                switch(dataChoice) {
                    case 1:
                        cin >> tmpstr;
                        *(find(recipients.begin(), recipients.end(), rec)) = Recipient(rec.ID(), rec.Name(), tmpstr, rec.Password(), rec.Age(), rec.Gender(), rec.Bloodtype(), rec.Hospital(), rec.DoctorOfCase());
                        break;

                    case 2:
                        cin >> tmpstr;
                        *(find(recipients.begin(), recipients.end(), rec)) = Recipient(rec.ID(), rec.Name(), rec.Mail(), tmpstr, rec.Age(), rec.Gender(), rec.Bloodtype(), rec.Hospital(), rec.DoctorOfCase());
                        break;

                    case 3:
                        cin >> tmpstr;
                        *(find(recipients.begin(), recipients.end(), rec)) = Recipient(rec.ID(), rec.Name(), rec.Mail(), rec.Password(), rec.Age(), rec.Gender(), rec.Bloodtype(), tmpstr, rec.DoctorOfCase());
                        break;

                    case 4:
                        cin >> tmpstr;
                        *(find(recipients.begin(), recipients.end(), rec)) = Recipient(rec.ID(), rec.Name(), rec.Mail(), rec.Password(), rec.Age(), rec.Gender(), rec.Bloodtype(), rec.Hospital(), tmpstr);
                        break;

                    default:
                        cout << "Invalid choice! Please try again";
                        pc(2, "Press any key to restart...");
                        recipientPage(rec);
                        return;
                }

                FileHandler::refreshEverything();
                cout << "Account updated successfully! You should re-login to experience changed effected!" << endl;
                pc(2, "Press any key to go back to login menu...");
                login();
                return;
            } break;

            case 2: { // recepientRequestBlood()
                string bloodtype;
                int quantity;

                cout << "Please enter the blood type you want to request: ";
                cin >> bloodtype;

                cout << "Please enter how much you need of this blood type: ";
                cin >> quantity;

                FileHandler::saveBloodRequest({Date(), bloodtype, quantity});
                cout << "Request sent successfully! An admin will check the request and reply as soon as possible..." << endl;
                pc(2, "Press any key to go back to main menu...");
            } break;

            case 3: { // recepientSearchAvailableBlood()
                string bloodtype;

                cout << "Please enter the blood type you want to search for: ";
                cin >> bloodtype;

                queue<AvailableBlood> temporaryQueue = database::availablebloodtypes;
                vector<AvailableBlood> found;

                while (!temporaryQueue.empty()) {
                    if (temporaryQueue.front().Bloodtype() == bloodtype) {
                        found.push_back(temporaryQueue.front());
                    }

                    temporaryQueue.pop();
                }

                if (found.empty()) {
                    cout << "We couldn't find the blood type you wanted in our list...";
                    pc(2, "Press any key to go back to main menu...");
                } else {
                    cout << "Found available blood: " << endl;
                    for (int i = 0; i < found.size(); i++) {
                        cout << "==============  #" << (i + 1) << "  ================" << endl;
                        cout << "====================================" << endl;
                        cout << "Received Date: " << found[i].date() << endl;
                        cout << "is expired: " << (found[i].isExpired() ? "Yes" : "No") << endl;
                        cout << "====================================" << endl << endl;
                    }

                    pc("Press any key to go back to main menu...");
                }
            } break;

            case 4: {
                recipients.erase(find(recipients.begin(), recipients.end(), rec));
                FileHandler::refreshEverything();
                cout << "Account deleted successfully! You are no longer registered in our systems!" << endl;
                pc(2, "Press any key to go back to main menu...");
            } break;

            case 5:
                login();
                return;

            default:
                cout << "Invalid choice! Please try again";
                pc(2, "Press any key to restart...");
        }

        recipientPage(rec);
    }

    void DonorLogin() {
        c();
        string username, password;
        cout << "Donor login Page: ";

        cout << "Username: ";
        cin >> username; // here we look for the mail
        cout << "Password: ";
        cin >> password;

        for (auto& don : database::donors) {
            if (username == don.Mail() && password == don.Password()) {
                cout << "Successful login! Please wait while we load you to main page" << endl;
                Sleep(2000);
                donorPage(don);
            }
        }

        cout << "We username/password are incorrect! Please try again or make sure you have registered in our system!" << endl;
        pc(2, "Press any key to go back to login menu...");
        login();
    }

    void RecipientLogin() {
        c();
        string username, password;
        cout << "Recipient login Page: " << endl << endl;

        cout << "Username: ";
        cin >> username; // here we look for the mail
        cout << "Password: ";
        cin >> password;

        for (auto& rec : database::recipients) {
            if (username == rec.Mail() && password == rec.Password()) {
                cout << "Successful login! Please wait while we load you to main page" << endl;
                Sleep(2000);
                recipientPage(rec);
                return;
            }
        }

        cout << "We username/password are incorrect! Please try again or make sure you have registered in our system!" << endl;
        pc(2, "Press any key to go back to login menu...");
        login();
    }

    void login() {
        c();
        int choice;

        cout << "Which type of login is it?";
        cout << "1- Donor\n2- Recipient\n3-Go Back\nYour choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                DonorLogin();
                break;

            case 2:
                RecipientLogin();
                break;

            case 3:
                start();
                return;

            default:
                cout << "Invalid choice! Please try again..." << endl;
                pc(1, "Press any button to restart..");
        }

        login();
    }

    void start() {
        c();
        int choice;

        cout << "What would you like to do?" << endl;
        cout << "1- login\n2- Sign up\n3- Exit\nYou choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                login();
                break;

            case 2:
                signup();
                break;

            case 3:
                cout << "Exiting...";
                return;

            default:
                cout << "Invalid choice! Please try again..." << endl;
                pc(1, "Press any button to restart..");
        }
        start();
    }
}

int main() {
    DriverCode::start();
}