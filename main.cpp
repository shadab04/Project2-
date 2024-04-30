#include<bits/stdc++.h>
using namespace std;
class BookManagement{
private:
struct Node
{
    int id;
    string title,author,category;
    Node* next;
};
public:
Node* head=NULL;
void insertBook();
void menu();
void updateBook();
void searchBook();
void deleteBook();
void showBooks();
void searchBookByCategory();

};
void BookManagement::menu()
{
    int choice;
    while(true)
    {
        cout<<"\n\t________Book Management System_________";
        cout<<"\n\nS.no                  Functions                Description"<<endl;
        cout<<"\n1 \tAdd BookS\t\tInsert new Book";
        cout<<"\n2 \tSearch Book\t\tSearch Book by ID";
        cout<<"\n3 \tUpdate Book\t\tUpdate Book Record";
        cout<<"\n4 \tDelete Book\t\tDelete Book by Id";
        cout<<"\n5 \tShow Book\t\tShow All Books";
        cout<<"\n6 \tSearch by category\tSearch Book by category";
        cout<<"\n7 \tExit"<<endl;
        
        cout<<"Enter your choice:";
        cin>>choice;

        switch (choice)
        {
        case 1:
            insertBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            updateBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            showBooks();
            break;
        case 6:
            searchBookByCategory();
            break;
        case 7:
            return;;
        default:
            cout<<"Invalid choice"<<endl;
        }

    }
}
void BookManagement::insertBook()
{
    Node* newBook=new Node();
    cout<<"\nEnter Book ID:";
    cin>>newBook->id;

    cout<<"\nEnter Book Title:";
    cin.ignore();
    getline(cin,newBook->title);

    cout<<"Enter Book Auther:";
    getline(cin,newBook->author);

    cout<<"Enter Book Category:";
    getline(cin,newBook->category);
    
    newBook->next=NULL;
    if(head==NULL)
    {
        head=newBook;
    }
    else{
        Node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newBook;
    }
    cout<<"\n New Book Inserted Successfully!"<<endl;
}
 
void BookManagement::searchBook()
{
    int bookId;
    cout<<"\nEnter Book ID:";
    cin>>bookId;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        if(bookId==ptr->id)
        {
            cout<<"\nBook ID:"<<ptr->id<<endl;
            cout<<"Book Title:"<<ptr->title<<endl;
            cout<<"Book Author:"<<ptr->author<<endl;
            return;
        }
        ptr=ptr->next;
    }
    cout<<"\nBook Not Found!"<<endl;
}
void BookManagement::updateBook()
{
    int bookId;
    cout<<"\nEnter Book ID:";
    cin>>bookId;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        if(bookId==ptr->id)
        {
            cout<<"\nBookID:"<<ptr->id<<endl;
            cout<<"Enter Update Book Title:";
            cin.ignore();
            getline(cin,ptr->title);
            cout<<"Enter Update Book Author:";
            getline(cin,ptr->author);
            cout<<"\nBook Record Update SUccessfully!"<<endl;
            return;
        }
        ptr=ptr->next;
    }
    cout<<"\nBook Not Found!"<<endl;
}
void BookManagement ::deleteBook()
{
    int bookId;
    cout<<"\nEnter Book ID:";
    cin>>bookId;

    if(head==NULL)
    {
        cout<<"\nBook List is Empty!"<<endl;
        return;
    }
    if(bookId==head->id)
    {
        Node* ptr=head;
        head=head->next;
        delete ptr;
        cout<<"\nBook Record Deleted Successfully!"<<endl;
        return;
    }
    Node* prev=head;
    Node* curr=head->next;
    while(curr!=NULL)
    {
        if(bookId==curr->id)
        {
            prev->next=curr->next;
            delete curr;
            cout<<"\nBook Record Deleted Successfully!"<<endl;
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    cout<<"\nBook NOt Found!"<<endl;
}
void BookManagement::showBooks()
{
    Node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<"\nBook ID:"<<ptr->id<<endl;
        cout<<"Book Title:"<<ptr->title<<endl;
        cout<<"Book Author:"<<ptr->author<<endl;
        ptr=ptr->next;
    }
}
void BookManagement:: searchBookByCategory()
{
    string category;
    cout<<"\nEnter Book Category:";
    cin.ignore();
    getline(cin,category);
    Node* ptr=head;
    bool found=false;
    while(ptr!=NULL)
    {
        if(category==ptr->category)
        {
            if(!found)
            {
                cout<<"\nBook in Category:"<<category<<endl;
                found=true;
            }
            cout<<"\nBook ID:"<<ptr->id<<endl;
            cout<<"Book Title:"<<ptr->title<<endl;
            cout<<"Book Author:"<<ptr->author<<endl;
        }
        ptr=ptr->next;
    }
    if(!found)
    {
        cout<<"\nNo Book found in the category :"<<category<<endl;
    }
}
int main()
{
    BookManagement bookManagement;
    bookManagement.menu();
    return 0;
}