template<class T> class list {
    private:
        // linkedlist data structure
        typedef struct _list
        {
            T value;
            struct _list *next;
        }slist;

        size_t _size;
        slist *front;
        slist *back;

    public:
        list() : _size{0}, front{nullptr}, back{nullptr} {}
        list()
        
};
