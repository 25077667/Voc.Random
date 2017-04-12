#include <bits/stdc++.h>
using namespace std;
string CheckFileName(string s)	//確認檔名不要重複txt 
{
	int n=s.size();
	string temp;
	if( s[n-1]=='t' && s[n-2]=='x' && s[n-3]=='t' && s[n-4]=='.' )
        { 
                for(int i=0;i<n-4;i++)
                        temp+=s[i];
                return temp;
        }
        else
                return s;
}

int main() {
        
        string filename,newfile; //main全域 string (檔名)宣告 
        stringstream ss;
		
        printf("你的名字:\n");
        getline (cin,filename);
		
        ifstream filein(filename.c_str());
        
        vector<string> fileword;
        fileword.resize(0);
        
        string tempword;
    	for (string line; getline(filein, tempword); ){
        	fileword.push_back(tempword);
    	}//將檔案寫入陣列 
        
        int n = fileword.size();//n代表檔案裡有幾個字 
        
        int newfilenum,nn;
        printf("需要幾份新文件:\n");
        cin >> newfilenum;
        nn = newfilenum-1;//確保第一次while的get被吃掉時補上get 
        
        int language;
        printf("English(1)/Chinese(2):\n");
        cin >> language;//1 or 2        
        if( language>2 || language<1 )    return 0;    //避免有人亂敲
        
        while(newfilenum--){
        
                bool Estate=0;//控制後方的:輸出 
                bool Cstate=0;//控制後方的:輸出 
                
                for(int i=0 ; i<n ; i++){
                        srand( time(NULL ) );
                        int randno = rand() % (n-i) + i;
                        swap( fileword[i] , fileword[randno] );
                }//隨機排列 
                
                printf("What's the name of newfile:\n\n");
                printf("plz put   .txt    at the end of file name\n");
                getline (cin,newfile);
                if ( nn==newfilenum ) getline (cin,newfile);//補上getline 
                ofstream fout( newfile.c_str() );
                
                if ( fout && language==1 ){
                    for(int i=0; i<n ; i++){
                                
                                int outword = 0;//輸出的字數 
                                
                                for(int j=0 ; j<fileword[i].length() && Estate==0 ; j++){
                                        if(fileword[i][j] != ':' && Estate==0){
                                            fout << fileword[i][j];
                                            outword ++;;
                                        }
                                        else {
                                                Estate = 1;
                                        }
                                }
                                Estate = 0;//只將:前的英文字先輸出
                        
                                if( outword < 35){
                                        int blank = ( 35 - outword )-1;
                                        while( blank-- ){
                                                fout << " ";
                                        }
                                }
                                if( (i+1)%2!=0 ){
                                        fout << "  ";
                                }
                                else{
                                        fout << endl << endl;
                                }//調整輸出文件排版適用於15px
                        }
                }
                
                if ( fout && language==2 ){
                        for(int i=0; i<n ; i++){
                                
                                int outword = 0;//輸出的字數 
                                
                                for(int j=0 ; j<fileword[i].length() ; j++){
                                        if(Cstate == 1){
                                                fout << fileword[i][j];
                                                outword++;
                                        }
                                        if(fileword[i][j] == ':') Cstate = 1; 
                                }
                                Cstate=0;//只將:後的華文字先輸出
                                
                                if( outword < 36){
                                        int blank = ( 36 - outword )-2;
                                        while( blank-- ){
                                                fout << " ";
                                        }
                                }
                                if( (i+1)%2!=0 ){
                                        fout << "  ";
                                }
                                else{
                                        fout << endl;
                                }//調整輸出文件排版適用於15px
                        }
                }
                
                
                string AnsFileString;	//用stringstream把char轉成string再增加 (ans).txt
                ss<<newfile;
                ss>>AnsFileString;
                AnsFileString=CheckFileName(AnsFileString);
                AnsFileString+="(ans).txt";
                
                char ansfile[]=" ";
                strcpy(ansfile,AnsFileString.c_str());		//把 AnsFileString的內容寫回ansfile 
                fstream fp;
                fp.open(ansfile , ios::out);

                for(int i=0; i<n ; i++){
                        fp << fileword[i];
                        fp << endl;
                }
                fp.close(); //將答案輸出 
                
        }
                
                
                cout << "===================";
                cout << endl << endl;
                cout << "檔案與答案輸出完成";
                cout << endl << endl;
                cout << "請將字體設定為15px";
                cout << endl << endl;
                cout << "並在列印前歸零所有邊框";
                cout << endl << endl;
                cout << "===================";
                cout << endl;
                system("pause");
        return 0;
}

/*
使用方法
輸入格式
英英英英:國國國國
如果選擇 英 就輸出:之前
如果選擇 國 就輸出:之後
解答一律輸出 英英英英:國國國國

待解決問題
Code problem
1.第一次while的get被吃掉
        解決辦法：暫無 僅能消極的用條件判斷

2.中英文分離CODE乾淨優化(優先)

Convenience
        1.解答檔自動命名 && 不重複(非常急)
        命名方式: "題目檔名"+"ans.txt"
*/

