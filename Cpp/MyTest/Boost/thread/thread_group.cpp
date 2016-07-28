thread_group tg;
tg.create_thread(bind(printing), ref(x), "C++"));
tg.create_thread(bind(printing), ref(x), "boost");
tg.join_all();

typedef singleton_default<thread_group> thread_pool;
thread_pool::instance().create_thread(...);