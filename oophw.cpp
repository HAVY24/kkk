#include <cstring> 
#include <iostream>

char* saochep(const char* s) {
    return strcpy(new char[strlen(s) + 1], s);
}

class Chuoi {
    char* p;

public:
    Chuoi(const char* s = "") {
        p = saochep(s);
    }

    ~Chuoi() {
        delete[] p;
    }

    void nhapchuoi() {
        char temp[100];
        std::cin.ignore();
        std::cin.getline(temp, 100);
        delete[] p;
        p = saochep(temp);
    }

    void xuatchuoi() const {
        std::cout << p;
    }

    bool sosanh(const Chuoi& s) const {
        return strcmp(p, s.p) == 0;
    }
};

class NgayThang {
    int day, month, year;

public:
    void nhapngaythang() {
        std::cin >> day >> month >> year;
    }

    void xuatngaythang() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

class Nguoi {
protected:
    Chuoi ID, HoTen;
    NgayThang Ngaysinh;

public:
    void nhapnguoi() {
        std::cin.ignore();
        ID.nhapchuoi();
        HoTen.nhapchuoi();
        Ngaysinh.nhapngaythang();
    }

    void xuatnguoi() const {
        ID.xuatchuoi();
        std::cout << "\t|";
        HoTen.xuatchuoi();
        std::cout << "\t|";
        Ngaysinh.xuatngaythang();
        std::cout << "\t|";
    }

    Chuoi get_id() const {
        return ID;
    }

    Chuoi get_hoten() const {
        return HoTen;
    }

    NgayThang get_ngaysinh() const {
        return Ngaysinh;
    }
};

class MonHoc {
private:
    Chuoi tenMonHoc;
    int soTiet;

public:
    void nhapmonhoc() {
        tenMonHoc.nhapchuoi();
        std::cin >> soTiet;
    }

    void xuatmonhoc() const {
        tenMonHoc.xuatchuoi();
        std::cout << "\t|" << soTiet << "\t|";
    }

    Chuoi get_tenmonhoc() const {
        return tenMonHoc;
    }

    int get_sotiet() const {
        return soTiet;
    }
};

class GiaoVien : public Nguoi {
private:
    Chuoi boMonCongTac;
    int soMonHoc;
    MonHoc danhSachMonHoc[10]; // Sử dụng mảng cố định thay vì vector

public:
    void nhapgiaovien() {
        Nguoi::nhapnguoi();
        boMonCongTac.nhapchuoi();
        std::cin >> soMonHoc;

        for (int i = 0; i < soMonHoc; ++i) {
            std::cout << "Nhap thong tin mon hoc thu " << i + 1 << ":" << std::endl;
            danhSachMonHoc[i].nhapmonhoc();
        }
    }

    void xuatgiaovien() const {
        Nguoi::xuatnguoi();
        boMonCongTac.xuatchuoi();
        std::cout << "\t|" << soMonHoc << "\t|";
        for (int i = 0; i < soMonHoc; ++i) {
            danhSachMonHoc[i].xuatmonhoc();
        }
        std::cout << std::endl;
    }

    int get_somonhoc() const {
        return soMonHoc;
    }

    const MonHoc* get_danhsachmonhoc() const {
        return danhSachMonHoc;
    }
};

void nhapdsgiaovien(GiaoVien* a, int& n) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].nhapgiaovien();
    }
}

void xuatdsgiaovien(const GiaoVien* a, int n) {
    std::cout << "ID\t|Full name\t|Date of birth\t|Subject\t|Number of subjects\n";
    for (int i = 0; i < n; i++) {
        a[i].xuatgiaovien();
    }
}

int main() {
    GiaoVien a[100];
    int n;
    nhapdsgiaovien(a, n);
    xuatdsgiaovien(a, n);
    return 0;
}
