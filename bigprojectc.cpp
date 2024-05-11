/*      PROJECT 6         */	
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const bool TINCHI = 0; 
const bool CHUONGTRINH = 1;

/* tao ra 2: class sinh vien gom co hoTen, MaSV, hinhThucHoc, Soluongtinchi */
class SinhVien {
private:
    string hoTen;
    string maSV;
    bool hinhThucHoc;
    int soLuong;
public:
    SinhVien() {
        hoTen = "";                   // thanh vien du lieu
        maSV = "";
        hinhThucHoc = TINCHI;
        soLuong = 0;
    }
    SinhVien(string hoTen, string maSV, bool hinhThucHoc, int soLuong) {  // constructer Sinhvien
        this->hoTen = hoTen;
        this->maSV = maSV;
        this->hinhThucHoc = hinhThucHoc;
        this->soLuong = soLuong;
    }

    string getHoTen() {
        return hoTen;
    }

    string getMaSV() {
        return maSV;
    }

    bool getHinhThucHoc() {  
        return hinhThucHoc;
    }

    int getSoLuong() {
        return soLuong;
    }

    void setHoTen(string hoTen) {
        this->hoTen = hoTen;
    }

    void setMaSV(string maSV) {
        this->maSV = maSV;
    }

    void setHinhThucHoc(bool hinhThucHoc) {
        this->hinhThucHoc = hinhThucHoc;
    }

    void setSoLuong(int soLuong) {
        this->soLuong = soLuong;
    }

    void nhap() {
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, this->hoTen);
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
        cout << "Nhap hinh thuc hoc (0: theo tin chi, 1: theo chuong trinh): ";
    	int x;
    	while (true) {
    		cin >> x;
    		if( x != 0 && x!= 1) {           // ep phai bang 0 hoac 1
    			cout << "Xin nhap lai hinh thuc hoc ( 0: theo tin chi, 1: theo chuong trinh): ";
			}
			else {
				break;   // thoat ra neu = 0 or = 1
			}
		}
		hinhThucHoc = x;
		cout<<"Nhap so luong tin chi : ";
		cin >> soLuong;
    }
    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ma sinh vien: " << maSV << endl;
        cout << "Hinh thuc hoc: " << (hinhThucHoc ? "theo chuong trinh mau" : "theo tin chi") << endl;   // Ternary operator
        cout << "So luong tin chi : " << soLuong << endl;
    }

};

/* tao class QuanLyHocPhi gom cac chuc nang them sua xoa tim sinh vien */
class QuanLyHocPhi : SinhVien {
private:
    vector<SinhVien> dsSinhVien;         
public:

    QuanLyHocPhi() {
        dsSinhVien.clear();
    }

    QuanLyHocPhi(vector<SinhVien> dsSinhVien, string name, string maSV, bool hinhthuchoc, int soLuong) : SinhVien(name, maSV, hinhthuchoc, soLuong) {
        this->dsSinhVien = dsSinhVien;
    }

    vector<SinhVien> getDsSinhVien() {
        return dsSinhVien;
    }

    void addSinhVien() {          // option 1
        SinhVien sv;              // tao doi tuong sv cua class Sinhvien 
        sv.nhap();                // minh dung ham nhap cua thang SinhVien
        dsSinhVien.push_back(sv); // push sv nhap vao dsSinhVien, 1 phuong thuc chuan cua vector
       
    }

    SinhVien searchSinhVien(string maSV) {                      // option 4
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i].getMaSV() == maSV) {
                return dsSinhVien[i];
            }
        }
        return SinhVien();
    }

    vector<SinhVien> searchSinhVienByHoTen(string hoTen) {        // option 4
        vector<SinhVien> dsSinhVienTimKiem;                       // vi co the co nhieu nguoi trung ten len phai tao 1 vector ds moi in toan bo ra
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i].getHoTen() == hoTen) {
                dsSinhVienTimKiem.push_back(dsSinhVien[i]);
            }
        }
        return dsSinhVienTimKiem;
    }

    vector<SinhVien> searchSinhVienBySoLuong(int soLuong) {        // option 4
        vector<SinhVien> dsSinhVienTimKiem;
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i].getSoLuong() == soLuong) {
                dsSinhVienTimKiem.push_back(dsSinhVien[i]);
            }
        }
        return dsSinhVienTimKiem;
    }

    vector<SinhVien> searchSinhVienByHinhThucHoc(bool hinhThucHoc) {   //option 7 8 
        vector<SinhVien> dsSinhVienTimKiem;
        for (int i = 0; i < dsSinhVien.size(); i++) {
            if (dsSinhVien[i].getHinhThucHoc() == hinhThucHoc) {
                dsSinhVienTimKiem.push_back(dsSinhVien[i]);
            }
        }
        return dsSinhVienTimKiem;
    }

    void deleteSinhVien(string maSV) {                          // option 3 cho xuong duoi de dung duoc option search
        SinhVien sv = searchSinhVien(maSV);
        if (sv.getHoTen() == "") {                              
            cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
        }
        else {
            for (int i = 0; i < dsSinhVien.size(); i++) {
                if (dsSinhVien[i].getMaSV() == maSV) {
                    dsSinhVien.erase(dsSinhVien.begin() + i);
                    break;
                }
            }
        }
    }

    void fixSinhVien(string maSV) {
        SinhVien sv = searchSinhVien(maSV);    
        SinhVien sv1;
        if (sv.getHoTen() == "") {
            cout << "Khong tim thay sinh vien co ma so " << maSV << endl;
        }
        else {
            sv1.nhap();                     // Nhap vao de thay the bang cach push vao
            dsSinhVien.push_back(sv1);      
            deleteSinhVien(maSV);
        }
    }


};


void printOption() {
    cout << "    Chuong trinh quan ly hoc phi sinh vien:   " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Them sinh vien" << endl;
    cout << "2. Sua thong tin sinh vien" << endl;
    cout << "3. Xoa sinh vien" << endl;
    cout << "4. Tim kiem sinh vien" << endl;
    cout << "5. In danh sach sinh vien hoc theo tin chi" << endl;
    cout << "6. In danh sach sinh vien hoc theo chuong trinh mau" << endl;
    cout << "7. Tinh hoc phi sinh vien theo tin chi" << endl;
    cout << "8. Tinh hoc phi sinh vien theo chuong trinh mau" << endl;
    cout << "0. Thoat" << endl;
}

int main() {

    QuanLyHocPhi qlhp;
    SinhVien sv;
    printOption();
    while (true) {
        int option;
        cout << "--------------------------------------------------";
        cout << "\n";
        cout << "Nhap lua chon: ";
        cin >> option;
        if (option == 0) {
            break;
        }
        else if (option == 1) {
            qlhp.addSinhVien();
        }
        else if (option == 2) {
            string maSV;
            cout << "Nhap ma sinh vien can sua: ";
            fflush stdin;
            cin >> maSV;
            qlhp.fixSinhVien(maSV);

        }
        else if (option == 3) {
            string maSV;
            cout << "Nhap ma sinh vien can xoa: ";
            fflush stdin;
            cin >> maSV;
            qlhp.deleteSinhVien(maSV);
        }
        else if (option == 4) {
            cout << "Tim kiem bang:" << endl;
            cout << "1. Theo ma sinh vien" << endl;
            cout << "2. Theo ho ten" << endl;
            cout << "3. Theo so luong tin chi" << endl;
            int o;
            cout << "Nhap lua chon: ";
            cin >> o;
            if (o == 1) {
                string maSV;
                cout << "Nhap ma sinh vien can tim: ";
                fflush stdin;
                cin >> maSV;
                SinhVien sv = qlhp.searchSinhVien(maSV);
                    if( sv.getMaSV() == ""){
                        cout << "KHong co sinh vien yeu cau !! " << endl;
                    }else{
                        sv.xuat();
                    }
            	}
            else if (o == 2) {
                string hoTen;
                cout << "Nhap ho ten can tim: ";
                fflush stdin;
                getline(cin, hoTen);
                vector<SinhVien> dsSinhVienTimKiem = qlhp.searchSinhVienByHoTen(hoTen);
                if( dsSinhVienTimKiem.size() == 0){
					cout << "Khong co sinh vien yeu cau !! " << endl;
				}else{
                for (int i = 0; i < dsSinhVienTimKiem.size(); i++) {
                    dsSinhVienTimKiem[i].xuat();
                	}
            	}
            }
            else if (o == 3) {
                int soLuong;
                cout << "Nhap so luong tin chi can tim: ";
                cin >> soLuong;
                vector<SinhVien> dsSinhVienTimKiem = qlhp.searchSinhVienBySoLuong(soLuong);
                if( dsSinhVienTimKiem.size() == 0){
					cout << "Khong co sinh vien yeu cau !! " << endl;
				}else{
                for (int i = 0; i < dsSinhVienTimKiem.size(); i++) {
                    dsSinhVienTimKiem[i].xuat();
                	}
				}
            }
        }
        else if (option == 5) {
            vector<SinhVien> dsSinhVienHocTinChi = qlhp.searchSinhVienByHinhThucHoc(false);
            if (dsSinhVienHocTinChi.size() == 0) {
                cout << "Khong co sinh vien hoc tin chi" << endl;
            }
            for (int i = 0; i < dsSinhVienHocTinChi.size(); i++) {
                dsSinhVienHocTinChi[i].xuat();
            }
        }
        else if (option == 6) {
            vector<SinhVien> dsSinhVienHocChuongTrinhMau = qlhp.searchSinhVienByHinhThucHoc(true);
            if (dsSinhVienHocChuongTrinhMau.size() == 0) {
                cout << "Khong co sinh vien hoc chuong trinh mau" << endl;
            }
            for (int i = 0; i < dsSinhVienHocChuongTrinhMau.size(); i++) {
                dsSinhVienHocChuongTrinhMau[i].xuat();
            }
        }
        else if (option == 7) {
            vector<SinhVien> dsSinhVienHocTinChi = qlhp.searchSinhVienByHinhThucHoc(false);
            if (dsSinhVienHocTinChi.size() == 0) {
                cout << "Khong co sinh vien hoc tin chi" << endl;
            }
            else {
                for (int i = 0; i < dsSinhVienHocTinChi.size(); i++) {
                    dsSinhVienHocTinChi[i].xuat();
                    cout << "Hoc phi cua sinh vien: " << dsSinhVienHocTinChi[i].getSoLuong() * 250 << " 000 VND\n\n";
                }
                int tongHocPhi = 0;
                for (int i = 0; i < dsSinhVienHocTinChi.size(); i++) {

                    tongHocPhi += dsSinhVienHocTinChi[i].getSoLuong() * 250;
                }
                cout << "Tong hoc phi sinh vien hoc tin chi: " << tongHocPhi << " 000 VND" << endl;
            }

        }
        else if (option == 8) {
            vector<SinhVien> dsSinhVienHocChuongTrinhMau = qlhp.searchSinhVienByHinhThucHoc(true);
            if (dsSinhVienHocChuongTrinhMau.size() == 0) {
                cout << "Khong co sinh vien hoc chuong trinh mau" << endl;
            }
            else {
                for (int i = 0; i < dsSinhVienHocChuongTrinhMau.size(); i++) {
                    dsSinhVienHocChuongTrinhMau[i].xuat();
                    cout << "Hoc phi cua sinh vien: " << dsSinhVienHocChuongTrinhMau[i].getSoLuong() * 2.5 * 250 + 1000 << " 000 VND\n\n";
                }
                int tongHocPhi = 0;
                for (int i = 0; i < dsSinhVienHocChuongTrinhMau.size(); i++) {
                    tongHocPhi += dsSinhVienHocChuongTrinhMau[i].getSoLuong() * 2.5 * 250 + 1000;
                }
                cout << "Tong hoc phi sinh vien hoc chuong trinh mau: " << tongHocPhi << " 000 VND" << endl;
            }
        }
    }

    return 0;
}
