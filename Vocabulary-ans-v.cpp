#include <bits/stdc++.h>
using namespace std;
string CheckFileName(string s)	//�T�{�ɦW���n����txt 
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
        
        string filename,newfile; //main���� string (�ɦW)�ŧi 
        stringstream ss;
		
        printf("�A���W�r:\n");
        getline (cin,filename);
		
        ifstream filein(filename.c_str());
        
        vector<string> fileword;
        fileword.resize(0);
        
        string tempword;
    	for (string line; getline(filein, tempword); ){
        	fileword.push_back(tempword);
    	}//�N�ɮ׼g�J�}�C 
        
        int n = fileword.size();//n�N���ɮ׸̦��X�Ӧr 
        
        int newfilenum,nn;
        printf("�ݭn�X���s���:\n");
        cin >> newfilenum;
        nn = newfilenum-1;//�T�O�Ĥ@��while��get�Q�Y���ɸɤWget 
        
        int language;
        printf("English(1)/Chinese(2):\n");
        cin >> language;//1 or 2        
        if( language>2 || language<1 )    return 0;    //�קK���H�úV
        
        while(newfilenum--){
        
                bool Estate=0;//�����誺:��X 
                bool Cstate=0;//�����誺:��X 
                
                for(int i=0 ; i<n ; i++){
                        srand( time(NULL ) );
                        int randno = rand() % (n-i) + i;
                        swap( fileword[i] , fileword[randno] );
                }//�H���ƦC 
                
                printf("What's the name of newfile:\n\n");
                printf("plz put   .txt    at the end of file name\n");
                getline (cin,newfile);
                if ( nn==newfilenum ) getline (cin,newfile);//�ɤWgetline 
                ofstream fout( newfile.c_str() );
                
                if ( fout && language==1 ){
                    for(int i=0; i<n ; i++){
                                
                                int outword = 0;//��X���r�� 
                                
                                for(int j=0 ; j<fileword[i].length() && Estate==0 ; j++){
                                        if(fileword[i][j] != ':' && Estate==0){
                                            fout << fileword[i][j];
                                            outword ++;;
                                        }
                                        else {
                                                Estate = 1;
                                        }
                                }
                                Estate = 0;//�u�N:�e���^��r����X
                        
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
                                }//�վ��X���ƪ��A�Ω�15px
                        }
                }
                
                if ( fout && language==2 ){
                        for(int i=0; i<n ; i++){
                                
                                int outword = 0;//��X���r�� 
                                
                                for(int j=0 ; j<fileword[i].length() ; j++){
                                        if(Cstate == 1){
                                                fout << fileword[i][j];
                                                outword++;
                                        }
                                        if(fileword[i][j] == ':') Cstate = 1; 
                                }
                                Cstate=0;//�u�N:�᪺�ؤ�r����X
                                
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
                                }//�վ��X���ƪ��A�Ω�15px
                        }
                }
                
                
                string AnsFileString;	//��stringstream��char�নstring�A�W�[ (ans).txt
                ss<<newfile;
                ss>>AnsFileString;
                AnsFileString=CheckFileName(AnsFileString);
                AnsFileString+="(ans).txt";
                
                char ansfile[]=" ";
                strcpy(ansfile,AnsFileString.c_str());		//�� AnsFileString�����e�g�^ansfile 
                fstream fp;
                fp.open(ansfile , ios::out);

                for(int i=0; i<n ; i++){
                        fp << fileword[i];
                        fp << endl;
                }
                fp.close(); //�N���׿�X 
                
        }
                
                
                cout << "===================";
                cout << endl << endl;
                cout << "�ɮ׻P���׿�X����";
                cout << endl << endl;
                cout << "�бN�r��]�w��15px";
                cout << endl << endl;
                cout << "�æb�C�L�e�k�s�Ҧ����";
                cout << endl << endl;
                cout << "===================";
                cout << endl;
                system("pause");
        return 0;
}

/*
�ϥΤ�k
��J�榡
�^�^�^�^:�����
�p�G��� �^ �N��X:���e
�p�G��� �� �N��X:����
�ѵ��@�߿�X �^�^�^�^:�����

�ݸѨM���D
Code problem
1.�Ĥ@��while��get�Q�Y��
        �ѨM��k�G�ȵL �ȯ�������α���P�_

2.���^�����CODE���b�u��(�u��)

Convenience
        1.�ѵ��ɦ۰ʩR�W && ������(�D�`��)
        �R�W�覡: "�D���ɦW"+"ans.txt"
*/

