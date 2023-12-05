#include<bits/stdc++.h>
using namespace std;

class Comment {
public:
    string content;
    Comment( const string& c) :  content(c) {}
};

class Post {
public:
    string content;
    int likes;
    vector<Comment> comments;

    Post(const string& c) : content(c), likes(0) {}

    void add_like() {
        likes++;
    }

    void add_comment( const string& content) {
        Comment newcomment( content);
        comments.push_back(newcomment);
    }

    void display() const {
        cout << "Post content :" << content << endl;
        cout << "Likes :" << likes << endl;
        cout << "Comments :" ;
        for (const auto& comment : comments) {
            cout << comment.content <<" ";
        }
        cout << endl;
        cout << "---x---x---x---x---x---x---x---"<<endl;
    }
};

int main() {
    vector<Post> posts;

    int choice;
    do {
        // system("cls");mj                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
        cout << "\t\t::Social Media Network" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "\t\t1. Create New Post" << endl;
        cout << "\t\t2. Display Posts" << endl;
        cout << "\t\t3. Add Likes" << endl;
        cout << "\t\t4. Add Comments" << endl;
        cout << "\t\t5. Exit" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\tEnter Your Choice :";
        cin >> choice;
        switch (choice) {
            case 1: {
                string content;
                cout << "Enter Content to Add :";
                cin.ignore();
                getline(cin, content);
                posts.emplace_back(content);
                cout << "Post Created" << endl;
                break;
            }
            case 2: {
                for (auto& post : posts) {
                    post.display();
                }
                // cout << "----------------------------" << endl;
                break;
            }
            case 3: {
                int postindex;
                cout << "Enter the Post number to like :";
                cin >> postindex;
                postindex = postindex - 1;
                if (postindex >= 0 && postindex < posts.size()) {
                    posts[postindex].add_like();
                    cout << "Like Added" << endl;
                } else {
                    cout << "Invalid Post Number" << endl;
                }
                break;
            }
            case 4: {
                int postindex;
                string comment;
                cout << "Enter the Post number to add Comment :";
                cin >> postindex;
                postindex = postindex - 1;
                if (postindex >= 0 && postindex < posts.size()) {
                    cout << "Enter Comment to add :";
                    cin.ignore();
                    getline(cin, comment);
                    posts[postindex].add_comment( comment);
                    cout << "Comment Added" << endl;
                } else {
                    cout << "Invalid Post Number" << endl;
                }
                break;
            }
            case 5: {
                exit(0);
                break;
            }
            default:
                cout << "Invalid choice, Try Again" << endl;
        }
    } while (choice != 5);

    return 0;
}
