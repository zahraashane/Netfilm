#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string judul[100];
double harga[100];
int tahun[100];
double rating[100];
int totalFilm = 0;
char kembali;

void loadFile()
{
    FILE *file = fopen("netfilm_db.txt", "r");
    if (file == NULL)
        return;
    char tempJudul[100];

    while (fscanf(file, " %[^;];%lf;%d;%lf\n",
                  tempJudul,
                  &harga[totalFilm],
                  &tahun[totalFilm],
                  &rating[totalFilm]) != EOF)
    {
        judul[totalFilm] = tempJudul;
        totalFilm++;
    }
    fclose(file);
    system("cls");
}

void saveFile()
{
    FILE *file = fopen("netfilm_db.txt", "w");

    for (int i = 0; i < totalFilm; i++)
    {
        fprintf(file, "%s;%.0lf;%d;%.1lf\n",
                judul[i].c_str(),
                harga[i],
                tahun[i],
                rating[i]);
    }
    fclose(file);
}

// Lihat Katalog Film. Menu 1

void katalogFilm()
{
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|      N E T F I L M      C O N T E N T       K A T A L O G     |" << endl;

    cout << string(65, '-') << endl;
    cout << "| " << left << setw(25) << "Judul"
         << "| " << left << setw(10) << "Harga"
         << "| " << left << setw(10) << "Tahun"
         << "| " << right << setw(10) << "Rating" << " |" << endl;
    cout << string(65, '-') << endl;

    for (int i = 0; i < totalFilm; i++)
    {
        cout << "| " << left << setw(25) << judul[i]
             << "| " << left << setw(10) << harga[i]
             << "| " << left << setw(10) << tahun[i]
             << "| " << right << setw(10) << fixed << setprecision(1) << rating[i] << " |" << endl;
    }
    cout << string(65, '-') << endl;

    cout << "\nKembali ke Menu Utama (y/t)? ";
    cin >> kembali;
    system("cls");
}

// Tambah Data Film. Menu 6

void tambahFilm()
{
    cin.ignore();

    cout << "---------------------------------------------------" << endl;
    cout << "       T A M B A H     D A T A     F I L M         " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "\nInput Judul Film : ";
    getline(cin, judul[totalFilm]);
    cout << "Input Harga Film : ";
    cin >> harga[totalFilm];
    cout << "Input Tahun Film : ";
    cin >> tahun[totalFilm];
    cout << "Input Rating Film : ";
    cin >> rating[totalFilm];
    cout << "---------------------------------------------------" << endl;
    totalFilm++;

    saveFile();

    cout << "\n[ SUCCESS ] Data film berhasil ditambahkan.";
    cout << "\nKembali ke Menu Utama (y/t)? ";
    cin >> kembali;
    system("cls");
}

// Bubble Sort. Menu 3

void bubbleSort()
{

    for (int i = 0; i < totalFilm - 1; i++)
    {
        for (int j = 0; j < totalFilm - i - 1; j++)
        {
            if (judul[j] > judul[j + 1])
            {
                swap(judul[j], judul[j + 1]);
                swap(harga[j], harga[j + 1]);
                swap(tahun[j], tahun[j + 1]);
                swap(rating[j], rating[j + 1]);
            }
        }
    }
    cout << "\n[ ! ] Katalog berhasil diurutkan berdasarkan Abjad (A-Z)\n";

    cout << string(65, '-') << endl;
    cout << "| " << left << setw(25) << "Judul"
         << "| " << left << setw(10) << "Harga"
         << "| " << left << setw(10) << "Tahun"
         << "| " << right << setw(10) << "Rating" << " |" << endl;
    cout << string(65, '-') << endl;

    for (int i = 0; i < totalFilm; i++)
    {
        cout << "| " << left << setw(25) << judul[i]
             << "| " << left << setw(10) << harga[i]
             << "| " << left << setw(10) << tahun[i]
             << "| " << right << setw(10) << fixed << setprecision(1) << rating[i] << " |" << endl;
    }
    cout << string(65, '-') << endl;

    cout << "\nKembali ke Menu Utama (y/t)? ";
    cin >> kembali;
    system("cls");
}

// Quick Sort. Menu 2

void quickSort(int awal, int akhir)
{
    int low = awal;
    int high = akhir;

    double pivot = rating[(awal + akhir) / 2];

    do
    {
        while (rating[low] > pivot)
            low++;
        while (rating[high] < pivot)
            high--;

        if (low <= high)
        {
            swap(judul[low], judul[high]);
            swap(harga[low], harga[high]);
            swap(tahun[low], tahun[high]);
            swap(rating[low], rating[high]);

            low++;
            high--;
        }
    } while (low <= high);

    if (awal < high)
        quickSort(awal, high);

    if (low < akhir)
        quickSort(low, akhir);

    if (awal == 0 && akhir == totalFilm - 1)
    {

        cout << "\n[ ! ] Katalog berhasil diurutkan berdasarkan Rating Tertinggi\n";

        cout << string(65, '-') << endl;
        cout << "| " << left << setw(25) << "Judul"
             << "| " << left << setw(10) << "Harga"
             << "| " << left << setw(10) << "Tahun"
             << "| " << right << setw(10) << "Rating" << " |" << endl;
        cout << string(65, '-') << endl;

        for (int i = 0; i < totalFilm; i++)
        {
            cout << "| " << left << setw(25) << judul[i]
                 << "| " << left << setw(10) << harga[i]
                 << "| " << left << setw(10) << tahun[i]
                 << "| " << right << setw(10) << fixed << setprecision(1) << rating[i] << " |" << endl;
        }
        cout << string(65, '-') << endl;

        cout << "\nKembali ke Menu Utama (y/t)? ";
        cin >> kembali;
        system("cls");
    }
}

// Linear Search Menu 4

void linearSearch()
{
    if (totalFilm >= 30)
    {
        cout << "\n[ ! ] Data Film >= 30. Silahkan searching menggunakan menu Binary Search.\n";
        cout << "\nKembali ke Menu Utama (y/t)? ";
        cin >> kembali;
        system("cls");
        return;
    }

    string cari;
    cin.ignore();

    cout << "---------------------------------------------------" << endl;
    cout << "|             C A R I        F I L M              |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "\nInput judul film yang dicari : ";
    getline(cin, cari);

    int ketemu = -1;
    int i = 0;

    while (i < totalFilm)
    {
        if (judul[i] == cari)
        {
            ketemu = i;
            break;
        }
        i++;
    }

    if (ketemu != -1)
    {
        cout << "\n[ SUCCESS ] Film ditemukan\n";
        cout << "---------------------------------------------------" << endl;
        cout << "Judul  : " << judul[ketemu] << endl;
        cout << "Harga  : " << harga[ketemu] << endl;
        cout << "Tahun  : " << tahun[ketemu] << endl;
        cout << "Rating : " << rating[ketemu] << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else
    {
        cout << "\n[ ! ] Film tidak ditemukan\n";
    }
    cout << "\nKembali ke Menu Utama (y/t)? ";
    cin >> kembali;
    system("cls");
}

// Binary Search. Menu 5

void binarySearch()
{
    if (totalFilm < 30)
    {
        cout << "\n[ ! ] Data Film < 30. Silahkan searching menggunakan menu Linear Search.\n";
        cout << "\nKembali ke Menu Utama (y/t)? ";
        cin >> kembali;
        system("cls");
        return;
    }

    string cari;
    cin.ignore();

    cout << "---------------------------------------------------" << endl;
    cout << "|             C A R I        F I L M              |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "\nInput judul film yang dicari : ";
    getline(cin, cari);

    int awal = 0;
    int akhir = totalFilm - 1;
    int ketemu = -1;
    int tengah;

    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (judul[tengah] == cari)
        {
            ketemu = tengah;
            break;
        }
        else if (cari < judul[tengah])
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = tengah + 1;
        }
    }

    if (ketemu != -1)
    {
        cout << "\n[ SUCCESS ] Film ditemukan\n";
        cout << "---------------------------------------------------" << endl;
        cout << "Judul  : " << judul[tengah] << endl;
        cout << "Harga  : " << harga[tengah] << endl;
        cout << "Tahun  : " << tahun[tengah] << endl;
        cout << "Rating : " << rating[tengah] << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else
    {
        cout << "\n[ ! ] Film tidak ditemukan\n";
    }

    cout << "\nKembali ke Menu Utama (y/t)? ";
    cin >> kembali;
    system("cls");
}

int main()
{
    loadFile();

    int pilihan;

    do
    {
        cout << "=========================================" << endl;
        cout << "|       NETFILM SYSTEM - DASHBOARD      |" << endl;
        cout << "=========================================" << endl;

        cout << "|[1] Lihat Katalog Film                 |" << endl;
        cout << "|[2] Urutkan Rating (Quick Sort)        |" << endl;
        cout << "|[3] Urutkan Abjad (Bubble Sort)        |" << endl;
        cout << "|[4] Cari Film (Linear Search)          |" << endl;
        cout << "|[5] Cari Film (Binary Search)          |" << endl;
        cout << "|[6] Tambah Film Baru                   |" << endl;
        cout << "|[0] Keluar & Simpan                    |" << endl;
        cout << "=========================================" << endl;
        cout << "\nPilih Menu  >> ";
        cin >> pilihan;
        system("cls");

        switch (pilihan)
        {

        case 1:
            katalogFilm();
            break;

        case 2:
            quickSort(0, totalFilm - 1);
            break;

        case 3:
            bubbleSort();
            break;

        case 4:
            linearSearch();
            break;

        case 5:
            binarySearch();
            break;

        case 6:
            tambahFilm();
            break;

        case 0:
            cout << "\n[ ! ] Program selesai.\n";
            break;

        default:
            cout << "\n[ ! ] Pilihan tidak valid.\n";
            cout << "Kembali ke Menu Utama (y/t)? ";
            cin >> kembali;
            system("cls");
        }
    } while (pilihan != 0);
}
