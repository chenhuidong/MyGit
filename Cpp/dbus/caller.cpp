#include <dbus.h>

int main()
{
DBusMessage* msg;
DBusMessageIter args;
DBusPendingCall* pending;
 
msg = dbus_message_new_method_call("test.method.server", // target for the method call
                                   "/test/method/Object", // object to call on
                                   "test.method.Type", // interface to call on
                                   "Method"); // method name
  if (NULL == msg) {
    fprintf(stderr, "Message Null\n");
    exit(1);
}
 
// append arguments
dbus_message_iter_init_append(msg, &args);
  if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &param)) {
    fprintf(stderr, "Out Of Memory!\n");
    exit(1);
}
 
// send message and get a handle for a reply
if (!dbus_connection_send_with_reply (conn, msg, &pending, -1)) { // -1 is default timeout
    fprintf(stderr, "Out Of Memory!\n"); 
    exit(1);
}
if (NULL == pending) {
    fprintf(stderr, "Pending Call Null\n");
    exit(1);
}
dbus_connection_flush(conn);
 
// free message
dbus_message_unref(msg);
} 