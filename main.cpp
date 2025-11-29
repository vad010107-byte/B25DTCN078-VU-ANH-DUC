#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Student {
public:
    string id, lastName, firstName, dob, gender, phone;

    void input() {
        cout << "Ma SV: ";        getline(cin, id);
        cout << "Ho dem: ";       getline(cin, lastName);
        cout << "Ten: ";          getline(cin, firstName);
        cout << "Ngay sinh: ";    getline(cin, dob);
        cout << "Gioi tinh: ";    getline(cin, gender);
        cout << "SDT: ";          getline(cin, phone);
    }

    void display() const {
        cout << left << setw(12) << id
             << setw(20) << lastName
             << setw(12) << firstName
             << setw(15) << dob
             << setw(10) << gender
             << setw(15) << phone << endl;
    }
};

//-----------------------------------------------------
// HÀM TÌM VỊ TRÍ SINH VIÊN THEO MÃ
//-----------------------------------------------------
int findIndex(const vector<Student>& ds, const string& id) {
    for (int i = 0; i < ds.size(); i++)
        if (ds[i].id == id) return i;
    return -1;
}

//-----------------------------------------------------
// HIỂN THỊ DANH SÁCH
//-----------------------------------------------------
void showList(const vector<Student>& ds) {
    if (ds.empty()) {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << left << setw(12) << "Ma SV"
         << setw(20) << "Ho dem"
         << setw(12) << "Ten"
         << setw(15) << "Ngay sinh"
         << setw(10) << "GT"
         << setw(15) << "SDT" << endl;
    cout << string(84, '-') << endl;

    for (auto &s : ds) s.display();
}

// CẬP NHẬT 1 TRƯỜNG DỮ LIỆU
string updateField(const string& oldValue, const string& label) {
    string tmp;
    cout << label << " (" << oldValue << "): ";
    getline(cin, tmp);
    return tmp.empty() ? oldValue : tmp;
}

// CHƯƠNG TRÌNH CHÍNH
int main() {
    vector<Student> ds;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Hien thi\n2. Them\n3. Cap nhat\n4. Sap xep A-Z\n5. Tim\n6. Xoa\n0. Thoat\nChon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) showList(ds);

        else if (choice == 2) {
            Student s;
            s.input();
            ds.push_back(s);
            cout << "Da them!\n";
        }

        else if (choice == 3) {
            string id;
            cout << "Nhap ma can cap nhat: "; getline(cin, id);
            int pos = findIndex(ds, id);

            if (pos < 0) cout << "Khong tim thay!\n";
            else {
                Student &s = ds[pos];
                s.lastName  = updateField(s.lastName,  "Ho dem");
                s.firstName = updateField(s.firstName, "Ten");
                s.dob       = updateField(s.dob,       "Ngay sinh");
                s.gender    = updateField(s.gender,    "Gioi tinh");
                s.phone     = updateField(s.phone,     "SDT");
                cout << "Cap nhat xong!\n";
            }
        }

        else if (choice == 4) {
            sort(ds.begin(), ds.end(),
                 [](const Student &a, const Student &b){
                     return a.firstName < b.firstName;
                 });
            cout << "Da sap xep!\n";
        }

        else if (choice == 5) {
            string key;
            cout << "Nhap ma hoac ten: "; getline(cin, key);
            bool ok = false;
            for (auto& s : ds)
                if (s.id == key || s.firstName == key)
                    s.display(), ok = true;
            if (!ok) cout << "Khong tim thay!\n";
        }

        else if (choice == 6) {
            string id;
            cout << "Nhap ma can xoa: "; getline(cin, id);
            int pos = findIndex(ds, id);
            if (pos < 0) cout << "Khong tim thay!\n";
            else ds.erase(ds.begin() + pos), cout << "Da xoa!\n";
        }

    } while (choice != 0);

    return 0;
}
