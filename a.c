include/dlt/dlt_user_macros.h:#define DLT_LOG_STRING(CONTEXT,LOGLEVEL,TEXT) \

src/adaptor/dlt-adaptor-stdin.c:            DLT_LOG(mycontext, DLT_LOG_INFO, DLT_STRING(str));
src/adaptor/dlt-adaptor-udp.c:            DLT_LOG(mycontext, DLT_LOG_INFO, DLT_STRING(recv_data));

src/dbus/dlt-dbus.c:        DLT_LOG(dbusLog,DLT_LOG_INFO,DLT_STRING("BusType"),DLT_STRING("Session Bus"));
src/dbus/dlt-dbus.c:        DLT_LOG(dbusLog,DLT_LOG_INFO,DLT_STRING("BusType"),DLT_STRING("System Bus"));
src/dbus/dlt-dbus.c:        DLT_LOG(dbusLog,DLT_LOG_INFO,DLT_STRING("BusType"),DLT_INT(type));
src/dbus/dlt-dbus.c:        DLT_LOG(dbusLog,DLT_LOG_INFO,DLT_STRING("FilterMatch"),DLT_UINT(num+1),DLT_STRING(config.DBus.FilterMatch[num]));
src/examples/dlt-example-non-ver

src/examples/dlt-example-user-common-api.c:        DLT_LOG_ID1(mycontext,DLT_LOG_INFO,11,DLT_UINT16(1011));
src/examples/dlt-example-user-common-api.c:        DLT_LOG_ID2(mycontext,DLT_LOG_INFO,12,DLT_UINT32(1012),DLT_UINT32(1013));
src/examples/dlt-example-user-common-api.c:        DLT_LOG_ID2(mycontext,DLT_LOG_INFO,13,DLT_UINT8(123),DLT_FLOAT32(1.12));
src/examples/dlt-example-user-common-api.c:        DLT_LOG_ID1(mycontext,DLT_LOG_INFO,14,DLT_STRING("DEAD BEEF"));

src/lib/dlt_filetransfer.c:            DLT_LOG(*fileContext,DLT_LOG_ERROR,DLT_STRING("dlt_user_log_file_infoAbout, Error getting size of file:"),DLT_STRING(filename));
src/lib/dlt_filetransfer.c:            DLT_LOG(*fileContext,DLT_LOG_ERROR,DLT_STRING("dlt_user_log_file_infoAbout, Error getting serial number of file:"),DLT_STRING(filename));
src/lib/dlt_filetransfer.c:            DLT_LOG(*fileContext,DLT_LOG_ERROR,DLT_STRING("dlt_user_log_file_infoAbout, Error getting creation date of file:"),DLT_STRING(filename));

src/tests/dlt-test-multi-process.c:        DLT_LOG(mycontext, DLT_LOG_INFO, DLT_STRING(PAYLOAD_DATA));

src/tests/dlt-test-user.c:    DLT_LOG(context_info,DLT_LOG_INFO,DLT_STRING("Test3: (Macro IF) finished"));
src/tests/dlt-test-user.c:    DLT_LOG(context_info,DLT_LOG_INFO,DLT_STRING("Test4: (Macro IF) Test different message sizes"));
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[3],DLT_LOG_INFO,DLT_STRING("1"),DLT_RAW(buffer,1));
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[3],DLT_LOG_INFO,DLT_STRING("16"),DLT_RAW(buffer,16));
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[3],DLT_LOG_INFO,DLT_STRING("256"),DLT_RAW(buffer,256));
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[3],DLT_LOG_INFO,DLT_STRING("1024"),DLT_RAW(buffer,1024));
src/tests/dlt-test-user.c:    DLT_LOG(context_info,DLT_LOG_INFO,DLT_STRING("Test4: (Macro IF) finished"));
src/tests/dlt-test-user.c:    DLT_LOG(context_info,DLT_LOG_INFO,DLT_STRING("Test5: (Macro IF) Test high-level API"));
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[4],DLT_LOG_INFO,DLT_STRING("Next line: DLT_LOG_INT"));
src/tests/dlt-test-user.c:    DLT_LOG_INT(context_macro_test[4], DLT_LOG_INFO, -42);
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[4],DLT_LOG_INFO,DLT_STRING("Next line: DLT_LOG_UINT"));
src/tests/dlt-test-user.c:    DLT_LOG_UINT(context_macro_test[4], DLT_LOG_INFO, 42);
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[4],DLT_LOG_INFO,DLT_STRING("Next line: DLT_LOG_STRING"));
src/tests/dlt-test-user.c:    DLT_LOG_STRING(context_macro_test[4], DLT_LOG_INFO, "String output");
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[4],DLT_LOG_INFO,DLT_STRING("Next line: DLT_LOG_RAW"));
src/tests/dlt-test-user.c:    DLT_LOG_RAW(context_macro_test[4],DLT_LOG_INFO, buffer,16);
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[4],DLT_LOG_INFO,DLT_STRING("Next line: DLT_LOG_STRING_INT"));
src/tests/dlt-test-user.c:    DLT_LOG_STRING_INT(context_macro_test[4], DLT_LOG_INFO, "String output: ", -42);

src/tests/dlt-test-user.c:    DLT_LOG_STRING_UINT(context_macro_test[4], DLT_LOG_INFO,"String output: ", 42);

src/tests/dlt-test-user.c:    DLT_LOG_STRING(context_info, DLT_LOG_INFO, "Test 9: (Macro IF) Test segmented network trace");

src/tests/dlt-test-user.c:    DLT_LOG(context_macro_callback, DLT_LOG_INFO, DLT_STRING("Injection received (macro IF). ID: "), DLT_UINT32(service_id),DLT_STRING("Data:"),DLT_STRING(text));
src/tests/dlt-test-user.c:    DLT_LOG(context_function_callback, DLT_LOG_INFO, DLT_STRING("Injection received (function IF). ID: "), DLT_UINT32(service_id),DLT_STRING("Data:"),DLT_STRING(text));

src/dbus/dlt-dbus.c:        DLT_LOG(dbusLog,DLT_LOG_INFO, DLT_CSTRING("BusType;") ,DLT_STRING("Session Bus"));
src/tests/dlt-test-user.c:    DLT_LOG(context_macro_test[4], DLT_LOG_INFO, DLT_INT(-42));
src/dbus/dlt-dbus.c:        DLT_LOG(dbusLog,DLT_LOG_INFO, DLT_STRING("BusType;") ,DLT_STRING("Session Bus"));
src/dbus/dlt-dbus.c:        DLT_LOG(dbusLog,DLT_LOG_INFO,
				DLT_STRING("BusType;")
				,DLT_STRING("Session Bus"));
