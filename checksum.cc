#include <nan.h>

int32_t CheckSum(const char *buff, int64_t size) {
    int32_t cksum = 0;
    while (size > 1) {
        cksum += *(unsigned short *) buff;
        buff += 2;
        size -= 2;
    }
    if (size) {
        cksum += *buff;
    }
    while (cksum >> 16)
        cksum = (cksum >> 16) + (cksum & 0xffff);
    return ~cksum;
}

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  char * buffer = (char*) node::Buffer::Data(info[0]->ToObject());
  unsigned int size = info[1]->Uint32Value();
  int32_t checksum = CheckSum(buffer, size);

  v8::Local<v8::Number> num = Nan::New(checksum);
  
  // info.GetReturnValue().Set(Nan::New(checksum).ToLocalChecked());
  info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("cal").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Method)->GetFunction());
}

NODE_MODULE(checksum, Init)
