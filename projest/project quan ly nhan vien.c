#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
 
struct Employee{
	char empId[50];
	char name[50];
	char position[15];
	int workDay;
	double baseSalary;
	char str_baseSalary[20];
	char str_workday[10];
};
typedef struct Employee NV;

struct TimeSheet{
	char logId[30];
	char empId[20];
	char date [20];
	char status[10];
};
typedef struct TimeSheet recordTimeSheet;
recordTimeSheet tsList[MAX];
int tscount=0;
NV listEmployee[MAX]={
    {"NV001", "Nguyen Van An", "Nhan Vien", 22, 5000000, "5000000", "22"},
    {"NV002", "Tran Thi Bao", "Nhan Vien", 20, 4800000, "4800000", "20"},
    {"NV003", "Le Van Cuong", "Truong Phong", 25, 8000000, "8000000", "25"},
    {"NV004", "Pham Thi Dung", "Nhan Vien", 18, 4500000, "4500000", "18"},
    {"NV005", "Hoang Van Em", "Nhan Vien", 21, 4700000, "4700000", "21"},
    {"NV006", "Dang Thi Giang", "Nhan Vien", 23, 4900000, "4900000", "23"},
    {"NV007", "Bui Van Hung", "Pho Phong", 24, 7500000, "7500000", "24"},
    {"NV008", "Nguyen Thi Hoa", "Nhan Vien", 19, 4600000, "4600000", "19"},
    {"NV009", "Tran Van Khoa", "Nhan Vien", 22, 5000000, "5000000", "22"},
    {"NV010", "Le Thi Lan", "Nhan Vien", 20, 4800000, "4800000", "20"},
    {"NV011", "Nguyen Van Minh", "Nhan Vien", 21, 4700000, "4700000", "21"},
    {"NV012", "Tran Thi Nga", "Nhan Vien", 22, 4900000, "4900000", "22"},
    {"NV013", "Le Van Quang", "Truong Phong", 25, 8000000, "8000000", "25"},
    {"NV014", "Pham Thi Re", "Nhan Vien", 20, 4600000, "4600000", "20"},
    {"NV015", "Hoang Van Son", "Nhan Vien", 23, 5000000, "5000000", "23"},
    {"NV016", "Dang Thi Thu", "Nhan Vien", 19, 4500000, "4500000", "19"},
    {"NV017", "Bui Van Tuan", "Pho Phong", 24, 7500000, "7500000", "24"},
    {"NV018", "Nguyen Thi Uyen", "Nhan Vien", 21, 4800000, "4800000", "21"},
    {"NV019", "Tran Van Vinh", "Nhan Vien", 22, 5000000, "5000000", "22"},
    {"NV020", "Le Thi Xuan", "Nhan Vien", 20, 4700000, "4700000", "20"}
};
int n_Employee=20;

void CreateNewEmployee();
void UpdateEmployee();
void PhysicalDeletion();
void DisplayEmployeelist();
void SearchEmployeeByName(); 
void SortEmployeeListByBaseSalary();
void TimeKeeping();  
void ViewPersenalTimesheet();
int isValidName(char *name);
int hasDigit(char *s);
int isNumber(const char x[]);
void toLowerCase(char *str);
int toInt2(char s[],int start){
	return (s[start]-'0')*10+(s[start+1]-'0');
}
int toInt4(char s[],int start){
	return (s[start]-'0')*1000+(s[start+1]-'0')*100+(s[start+2]-'0')*10+(s[start+3]-'0');
}
int DuplicateEmployeeId(char Id[]);
int isAllSpace(char c[]);
int isValidate(char date[]);
int main (){
	int choice;
	char str_choice[9];
	while(1){
		system("cls");
		printf("\n+----------------Menu-----------------+");
		printf("\n|1.Them nhan vien moi.                |");
		printf("\n|2.Cap nhat ho so sinh vien.          |");
		printf("\n|3.Quan ly nhan su(sa thai nhan vien).|");
		printf("\n|4.Hien thi danh sach.                |");
		printf("\n|5.Tra cuu (tim kiem).                | ");
		printf("\n|6.Sap xep danh sach.                 |");
		printf("\n|7.Cham cong.                         |");
		printf("\n|8.Xem bang cong.                     |");
		printf("\n|9.Thoat.                             |");
		printf("\n+-------------------------------------+");
		printf("\nChon chuc nang :");
		fgets(str_choice,sizeof(str_choice),stdin);
		str_choice[strcspn(str_choice,"\n")]='\0';
		if(strlen(str_choice)==0 || isAllSpace(str_choice) || !isNumber(str_choice)){
			printf("Loi:chua lua chon chuc nang hoac nhap sai ki tu !!\n");
			getchar();
			continue;
		}
		choice = atoi(str_choice);
		switch(choice){
			case 1:{
				CreateNewEmployee();
				printf("\nAn enter de thoat chuc nang va ve menu chinh .\n");
				getchar();
				break;
			}
			case 2:	{
				UpdateEmployee();
				printf("\nAn enter de thoat chuc nang va ve menu chinh .\n");
				getchar(); 
				break;
			}
			case 3:{
				PhysicalDeletion();
				printf("\nAn enter de thoat chuc nang va ve menu chinh .\n");
				getchar();
				break;
			}
			case 4:{
				DisplayEmployeelist();
				break;
			}
			case 5:{
				SearchEmployeeByName();
				printf("\nAn enter de thoat chuc nang va ve menu chinh .\n");
				getchar(); 
				break;
			}
			case 6:{
				SortEmployeeListByBaseSalary();
				break;
			}
			case 7:{
				TimeKeeping();
				printf("\nAn enter de thoat chuc nang va ve menu chinh .\n");
				getchar();
				break;
			}
			case 8:{
				ViewPersenalTimesheet();
				printf("\nAn enter de thoat chuc nang va ve menu chinh .\n");
				getchar(); 
				break;
			}
			case 9:{				
				printf("Cam on vi da su dung chuong trinh\n");
				return 0;
				break;
			}
			default:{
				printf("Vui long nhap tu 1-9\n");
				printf("Chon enter de quay lai menu\n");
				getchar();
				break;
			}		
		}
	}
}

void CreateNewEmployee(){
		NV s;
		do{
			if(n_Employee>=MAX){
				printf("Loi:danh sach da day !!\n");
				return;
			}
			printf("Nhap thong tin cho nhan vien \n");
			printf("Moi nhap ma nhan vien: ");
			fgets(s.empId,sizeof(s.empId),stdin);
			s.empId[strcspn(s.empId,"\n")]='\0';
			if(strlen(s.empId)==0 || isAllSpace(s.empId)){
				printf("Voi chua nhap empId !!!\n");
			}else{
				if(DuplicateEmployeeId(s.empId)){
					printf("Loi empId bi trung !!\n");
				}
			}
		}while(strlen(s.empId)==0 || isAllSpace(s.empId) || DuplicateEmployeeId(s.empId));
		
		do{
			printf("Nhap ten nhan vien :");
			fgets(s.name,sizeof(s.name),stdin);
			s.name[strcspn(s.name,"\n")]='\0';
			if(strlen(s.name)==0 || isAllSpace(s.name)){
				printf("Loi chua nhap ten nhan vien !!\n");
			}else{
				if(!isValidName(s.name)){
					printf("Vui long nhap lai ten nhan vien!\n");
				}
			}
		}while(strlen(s.name)==0 || isAllSpace(s.name) || !isValidName(s.name));
		
		do{
			printf("Nhap chuc vu cua nhan vien: ");
			fgets(s.position,sizeof(s.position),stdin);
			s.position[strcspn(s.position,"\n")]='\0';
			if(strlen(s.position)==0 || isAllSpace(s.position)){
				printf("Loi chua nhap chuc vu sinh vien !!!\n");
			}else{
				if(!isValidName(s.position)){
					printf("Vui long nhap lai chuc vu cua nhan vien!\n");
				}
			}
		}while(strlen(s.position)==0 || isAllSpace(s.position) || !isValidName(s.position));
		
		do{
			printf("Nhap so tien luong: ");
			fgets(s.str_baseSalary,sizeof(s.str_baseSalary),stdin);
			s.str_baseSalary[strcspn(s.str_baseSalary,"\n")]='\0';
			if(strlen(s.str_baseSalary)==0 || isAllSpace(s.str_baseSalary)){
				printf("LoI:khong duoc de trong  !!\n");
			}else if(!isNumber(s.str_baseSalary)){
				printf("Loi:khong duoc nhap chu, so khong duoc mang gia tri am!\n");
			}else{
				s.baseSalary=atoi(s.str_baseSalary);
				if(s.baseSalary<0){
				printf("Loi:khong phai so duong!!\n");
				}
			}
			
		}while(s.baseSalary<0 || strlen(s.str_baseSalary)==0 || isAllSpace(s.str_baseSalary) || !isNumber(s.str_baseSalary));
		
		do{
			printf("Nhap so ngay cong:");
			fgets(s.str_workday,sizeof(s.str_workday),stdin);
			s.str_workday[strcspn(s.str_workday,"\n")]='\0';
			if(strlen(s.str_workday)==0 || isAllSpace(s.str_workday)){
					printf("Loi : khong duoc de trong va khong duoc nhap chu !!\n");
				}else{
					if(!isNumber(s.str_workday)){
						printf("Loi:ngay cong khong duoc nhap chu,khong duoc de so am!\n");
					}
				}
		}while(!isNumber(s.str_workday)|| strlen(s.str_workday)==0 || isAllSpace(s.str_workday) );

		
		listEmployee[n_Employee]=s;
		n_Employee++; 
	
	printf("Da them nhan vien thanh cong");	
}

void UpdateEmployee(){
	char SearchEmpId[20];
	char newPosition[50];
	double newBaseSalary;
	char str_newBaseSalary[10];
	do{
		printf("\nNhap ma nhan vien can cap nhat ho so : ");
		fgets(SearchEmpId,sizeof(SearchEmpId),stdin);
		SearchEmpId[strcspn(SearchEmpId,"\n")]='\0';
		if(strlen(SearchEmpId)==0 || isAllSpace(SearchEmpId)){
			printf("Loi: ban chua nhap ma nhan vien can cap nhat!!\n ");
		}else{
			if(!DuplicateEmployeeId(SearchEmpId)){
				printf("Loi: ma nhan vien khong ton tai!!\n");
			}
		}
	}while(strlen(SearchEmpId)==0 || isAllSpace(SearchEmpId) || !DuplicateEmployeeId(SearchEmpId));
	for(int i=0;i<n_Employee;i++){
		if(strcmp(listEmployee[i].empId,SearchEmpId)==0){
			printf("Thong tin cua cu nhan vien ma so %s co thong tin la \n",SearchEmpId);
				printf("\n-----------------------------Danh sach nhan vien---------------------------------\n");
				printf("|%-10s|%-20s|%-15s|%-15s|%-15s|\n","MaNV","Ten nhan vien","Chuc vu","Luong co ban","So ngay cong");
				for(int i=0;i<81;i++){
					printf("-");
				}
				printf("\n");
					printf("|%-10s|%-20s|%-15s|%-15.2f|%-15d|\n",listEmployee[i].empId,listEmployee[i].name,listEmployee[i].position,listEmployee[i].baseSalary,listEmployee[i].workDay);	
				for(int i=0;i<81;i++){
					printf("-");
				}
			do{
				printf("\nCap nhat chuc vu moi cho nhan vien ma %s:",SearchEmpId);
				fgets(newPosition,sizeof(newPosition),stdin);
				newPosition[strcspn(newPosition,"\n")]='\0';
				if(strlen(newPosition)==0 || isAllSpace(newPosition)){
					printf("Loi: ban chua cap nhat chuc vu noi cho nhan vien !!\n");
					continue;
				}
				if(!isValidName(newPosition)){
					printf("Loi: chuc vu khong duoc nhap so!!\n");
					continue;
				}
				break;
				
			}while(1);
			strcpy(listEmployee[i].position,newPosition);
			
			do{
				printf("Cap nhat bang luong moi cho nhan vien :");
				fgets(str_newBaseSalary,sizeof(str_newBaseSalary),stdin);
				str_newBaseSalary[strcspn(str_newBaseSalary,"\n")]='\0';
				//------ktra trong-----------
				if(strlen(str_newBaseSalary)==0 || isAllSpace(str_newBaseSalary)){
					printf("Loi :khong duoc de trong !!\n");
					continue;
				} 
				if(!isNumber(str_newBaseSalary)){
					printf("Loi:khong duoc nhap chu,khong duoc nhap so am!!\n");
					continue;
				}
				newBaseSalary=atoi(str_newBaseSalary);
				if(newBaseSalary<0){
					printf("Loi:khong phai la so duong!\n");
					continue;
				}
				break;
			
			}while(1);
				listEmployee[i].baseSalary=newBaseSalary;
				printf("Thong tin nhan vien da cap nhat thanh cong.");
				return;
		}
	} 
}


void PhysicalDeletion(){
	char searchId[20];
	char c; 
	do{
		printf("Nhap ma nhan vien can sa thai:");
		fgets(searchId,sizeof(searchId),stdin);
		searchId[strcspn(searchId,"\n")]='\0';
		if(strlen(searchId)==0 || isAllSpace(searchId)){
			printf("Loi: ma sinh vien khong duoc de trong.\n");
		}else{
			if(!DuplicateEmployeeId(searchId)){
				printf("Loi: khong tim thay nhan vien co ma %s\n",searchId);
			}
		}
	}while(strlen(searchId)==0 || isAllSpace(searchId) || !DuplicateEmployeeId(searchId));
	do{
	
		printf("Ban chac chan muon sa thai nhan vien nay ? 'C':co || 'K':khong\n");
		scanf(" %c",&c);
		while(getchar()!='\n');
		if(c=='C' || c=='c'){
			for(int i=0;i<n_Employee;i++){
				if(strcmp(listEmployee[i].empId,searchId)==0){
					for(int j=i;j<n_Employee-1;j++){
						listEmployee[j]=listEmployee[j+1];
					}
					n_Employee--;
					printf("Da xoa nhan vien ma %s thanh cong .\n",searchId);
					return;
				}
			}
		}else if(c=='k' || c=='K'){
			printf("Nguoi dung chua chap nhan xoa nhan vien \n");
			return ; 
		}else{
			printf("vui long chon 'C'hoac'K' ");
		}
	}while(1);
}


void DisplayEmployeelist(){
    int PageSize = 5;
    int currentPage = 1;
    int totalPage;
    if(n_Employee == 0){
        printf("Danh sach nhan vien hien dang trong!! \n");
        return;
    }
    if(n_Employee % PageSize == 0){
        totalPage = n_Employee / PageSize;
    } else {
        totalPage = n_Employee / PageSize + 1;
    }
    
    while(1){
        int start = (currentPage - 1) * PageSize;
        int end = start + PageSize; 
        system("cls");
        printf("\n====================================================================================\n");
        printf("||                                       Page %d/%d                                ||\n", currentPage, totalPage);
        printf("====================================================================================\n\n");
        printf("\n-----------------------------Danh sach nhan vien---------------------------------\n");
        printf("|%-10s|%-20s|%-15s|%-15s|%-15s|\n","MaNV","Ten nhan vien","Chuc vu","Luong co ban","So ngay cong");
        for(int i = 0; i < 81; i++) printf("-");
        printf("\n");

        for(int i = start ; i < end ; i++){
            if(i < n_Employee){
                printf("|%-10s|%-20s|%-15s|%-15.2f|%-15d|\n",
                       listEmployee[i].empId,
                       listEmployee[i].name,
                       listEmployee[i].position,
                       listEmployee[i].baseSalary,
                       listEmployee[i].workDay);  
                for(int j = 0; j < 81; j++) printf("-");
                printf("\n");
            }   
        }       

        printf("\nNhap trang can xem (1-%d) hoac 0 de thoat: ", totalPage);
        int pageInput;
        scanf("%d", &pageInput);
        while(getchar() != '\n');

        if(pageInput == 0){
            return;
        } else if(pageInput >= 1 && pageInput <= totalPage){
            currentPage = pageInput;
        } else {
            printf("Trang khong hop le! Nhan phim enter de tiep tuc...");
            getchar();
        }
    }
}

void SearchEmployeeByName(){
	char SearchName[50];
	char tempName[50];
	int found=0;
	do{
		printf("Moi nhap ten nhan vien can tim kiem :");
		fgets(SearchName,sizeof(SearchName),stdin);
		SearchName[strcspn(SearchName,"\n")]='\0';
		if(strlen(SearchName)==0 || isAllSpace(SearchName) || isNumber(SearchName)){
			printf("Loi: chua nhap ten nhan vien can tim kiem va ten nhan vien khong phai so !!!\n");
		}
	}while(strlen(SearchName)==0 || isAllSpace(SearchName) || isNumber(SearchName));
	
	printf("\n-----------------------------Danh sach nhan vien---------------------------------\n");
		printf("|%-10s|%-20s|%-15s|%-15s|%-15s|\n","MaNV","Ten nhan vien","Chuc vu","Luong co ban","So ngay cong");
		for(int i=0;i<81;i++){
			printf("-");
		}
		printf("\n"); 
		toLowerCase(SearchName);
	for(int i=0;i<n_Employee;i++){
		strcpy(tempName,listEmployee[i].name);
		toLowerCase(tempName);
		if(strstr(tempName,SearchName)!=NULL){
				found=1;
				printf("|%-10s|%-20s|%-15s|%-15.2f|%-15d|\n",listEmployee[i].empId,listEmployee[i].name,listEmployee[i].position,listEmployee[i].baseSalary,listEmployee[i].workDay);	
		     }	
		} 
		for(int k=0;k<81;k++){
			printf("-");
			}
			printf("\n");
		if(found!=1){
			printf("\n-----------------------------Danh sach nhan vien---------------------------------\n");
			printf("|%-10s|%-20s|%-15s|%-15s|%-15s|\n","maNV","ten nhan vien","chuc vu","luong co ban","so ngay cong");
			for(int i=0;i<81;i++){
				printf("-");
			}
			printf("\n");
			printf("|                              Khong tim thay nhan vien                         |");
			printf("\n+-------------------------------------------------------------------------------+");
		} 
		 
		
			
}


void SortEmployeeListByBaseSalary(){
	int type;
	char str_type[3];
	if(n_Employee==0){
		printf("Danh sach nhan vien hien dang trong!! \n");
		return; 
	}
	while(1){
		system("cls");
		printf("Chon kieu sap xep theo bang luong :\n");
		printf("\n+----Menu---+");
		printf("\n|0.Thoat!   |");
		printf("\n|1.Tang dan.|");
		printf("\n|2.Giam dan.|");
		printf("\n+-----------+");
		printf("\nChon chuc nang:");
		fgets(str_type,3,stdin);
		str_type[strcspn(str_type,"\n")]='\0';
		if(strlen(str_type)==0 || isAllSpace(str_type) || !isNumber(str_type)){
			printf("Loi: chua lua chon chuc nang hoac nhap sai ky tu !!\n");
			getchar();
			continue;
		}
		type=atoi(str_type);
		switch(type){
			case 1:{
				for(int i=0;i<n_Employee;i++){
					for(int j=0;j<n_Employee-i-1;j++){
						if(listEmployee[j].baseSalary>listEmployee[j+1].baseSalary){
							NV temp=listEmployee[j];
							listEmployee[j]=listEmployee[j+1];
							listEmployee[j+1]=temp;
						}
					}
				}
					printf("Da sap xep tang dan thanh cong \n");
				break;
			}
			case 2:{
					for(int i=0;i<n_Employee;i++){
						for(int j=0;j<n_Employee-i-1;j++){
							if(listEmployee[j].baseSalary<listEmployee[j+1].baseSalary){
								NV temp=listEmployee[j];
								listEmployee[j]=listEmployee[j+1];
								listEmployee[j+1]=temp;
						}
					}
				}
				printf("Da sap xep giam dan thanh cong \n");
				break;
			}
			case 0:{
				return;
				break;
			} 
			default:{
				printf("Vui long chon 0-2 !!\n");
				break;
			} 
		}
		printf("\n----------------------------- Danh sach nhan vien ---------------------------------\n");
        printf("|%-10s|%-20s|%-15s|%-15s|%-15s|\n","MaNV","Ten nhan vien","Chuc vu","Luong co ban","So ngay cong");
        for(int k=0;k<81;k++) printf("-");
        printf("\n");

        for(int i=0;i<n_Employee;i++){
            printf("|%-10s|%-20s|%-15s|%-15.2f|%-15d|\n",
                listEmployee[i].empId,
                listEmployee[i].name,
                listEmployee[i].position,
                listEmployee[i].baseSalary,
                listEmployee[i].workDay);
                
        for(int k=0;k<81;k++) printf("-");
        printf("\n");
        }
        printf("\n");
        printf("vui long an enter de quay ve muc lua chon chuc nang tang giam !!\n");
        getchar();
		
	} 	
}


void TimeKeeping(){
	char searchIdEmp[50];
	char Searchdate[50];int days;int month;int year;

	do{
		printf("Nhap ma nhan vien :");
		fgets(searchIdEmp,sizeof(searchIdEmp),stdin);
		searchIdEmp[strcspn(searchIdEmp,"\n")]='\0';
		if(strlen(searchIdEmp)==0 || isAllSpace(searchIdEmp)){
			printf("khong duoc de trong ma nv!!\n");
		}else{
			if(!DuplicateEmployeeId(searchIdEmp)){
				printf("Ma nhan vien %s khong ton tai trong danh sach",searchIdEmp);
				return;
			}
		}
	}while(strlen(searchIdEmp)==0 || isAllSpace(searchIdEmp) || !DuplicateEmployeeId(searchIdEmp));
	

	do{
		printf("Nhap ngay cham cong(dd/mm/yyyy):");
		fgets(Searchdate,sizeof(Searchdate),stdin);
		Searchdate[strcspn(Searchdate,"\n")]='\0';
		if(!isValidate(Searchdate) || strlen(Searchdate)==0){
			printf("Loi: nhap ngay cham cong khong hop le !!\n");	
		}else break; 
	}while(!isValidate(Searchdate) || strlen(Searchdate)==0);
	

	for(int i=0;i<tscount;i++){
		if(strcmp(tsList[i].empId,searchIdEmp)==0 && strcmp(tsList[i].date,Searchdate)==0){
			printf("Da cham cong ngay %s roi ",Searchdate);
			return; 
		}	
	}
	for(int i=0;i<n_Employee;i++){
		if(strcmp(listEmployee[i].empId,searchIdEmp)==0){
			listEmployee[i].workDay++;
			break;
		}
	} 	
	int countlogs=0;
		for(int i=0;i<tscount;i++){
			if(strcmp(tsList[i].empId,searchIdEmp)==0){
				countlogs++;
			}
		} 
		strcpy(tsList[tscount].status,"Di lam"); 
		strcpy(tsList[tscount].empId,searchIdEmp);
		strcpy(tsList[tscount].date,Searchdate);
		sprintf(tsList[tscount].logId,"%d",countlogs+1); 
		tscount++;
		
	printf("Da cham cong thanh cong\n");
}
void ViewPersenalTimesheet(){
    char Id_nv[50];
    int month;
    do{
        printf("Nhap ma nhan vien can xem bang cong: ");
        fgets(Id_nv, sizeof(Id_nv), stdin);
        Id_nv[strcspn(Id_nv, "\n")] = '\0';
        if(strlen(Id_nv)==0 || isAllSpace(Id_nv)){
            printf("Loi: khong duoc de trong!!\n");
        }else if(!DuplicateEmployeeId(Id_nv)){
            printf("Ma nhan vien khong ton tai !!\n");
        }
    }while(strlen(Id_nv)==0 || isAllSpace(Id_nv) || !DuplicateEmployeeId(Id_nv));
    
    do{
        printf("Nhap thang muon xem (1-12): ");
        scanf("%d", &month);
        if(month < 1 || month > 12){
            printf("Thang khong hop le! Moi nhap lai.\n");
        }
    }while(month < 1 || month > 12);
    while(getchar()!='\n'); 
    int daysInMonth;
    if(month==2){
        daysInMonth = 28;
    } else if(month==4 || month==6 || month==9 || month==11){
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    printf("\n+------------Bang cong ca nhan-------------+\n");
    printf("Thang: %02d\n", month);
    printf("|%-10s|%-15s|%-15s|\n","LogId","Ngay cham","Trang thai");
    for(int i = 0; i < 44; i++) printf("-");
    printf("\n");
    int found = 0;
    for(int day=1; day<=daysInMonth; day++){
        int dayFound = 0;
        for(int i=0; i<tscount; i++){
            int d, m, y;
            if(strcmp(tsList[i].empId, Id_nv) == 0){
                sscanf(tsList[i].date, "%d/%d/%d", &d, &m, &y);
                if(d == day && m == month){
                    printf("|%-10s|%-15s|%-15s|\n",
                        tsList[i].logId,
                        tsList[i].date,
                        tsList[i].status
                    );
                    dayFound = 1;
                    found = 1;
                    break;
                }
            }
        }
        if(!dayFound){
            printf("|%-10s|%02d/%02d/%04d     |%-15s|\n",
                   "-", day, month, 2025, "Nghi lam");
        }
    }
    for(int i = 0; i < 44; i++) printf("-");
    printf("\n");
    if(!found){
        printf("Khong co du lieu cham cong trong thang %02d ! Tat ca la Nghi lam.\n", month);
    }
}



int isValidate(char date[]){
	if(strlen(date)!=10)return 0;
	if(date[2] != '/' || date[5] != '/')return 0;
	
	for(int i=0;i<10;i++){
		if(i==2 || i==5) continue;
		if(!isdigit(date[i])) return 0;
	}
	int days=toInt2(date,0);
	int month=toInt2(date,3);
	int year =toInt4(date,6);
	
	if(year<1900 || year>2025)
		return 0;
		
	if(month<1 || month>12)
		return 0;
		
	if(days<1){
		return 0;
	}else if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12 ){
		if(days>31){
			return 0;
		}
	}else if(month == 2){
		if(year % 400 == 0 || year % 4 == 0 && year % 100 != 0){
			if(days>29){
				return 0;
			}
		}else{
			if(days>28){
				return 0;
			}
		}
	}else if (month == 4 || month == 6 || month == 9 || month == 11){
		if(days>30){
			return 0;
		}
	}
	
	return 1;
}

int DuplicateEmployeeId(char Id[]){
	for(int i=0 ;i<n_Employee;i++){
		if(strcmp(listEmployee[i].empId,Id)==0){
			return 1;
		}
	}
	return 0;
}


int isAllSpace(char c[]) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] != ' ') return 0;
    }
    return 1;
}

void toLowerCase(char *str){
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

int isNumber(const char x[]){
    for(int i=0; i<strlen(x); i++){
        if(!isdigit(x[i])) return 0;
    }
    return 1;
}

int isValidName(char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        char c = name[i];
        if (isalpha((unsigned char)c) || c == ' ')
            continue;
        return 0;
    }
    return 1; 
}

