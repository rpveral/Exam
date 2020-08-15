#include "functions.h"

using v8::FunctionTemplate;

// NativeExtension.cc represents the top level of the module.
// C++ constructs that are exposed to javascript are exported here

NAN_MODULE_INIT(InitAll) {
  Nan::Set(target, Nan::New("monitor").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(monitor)).ToLocalChecked());
  Nan::Set(target, Nan::New("lastinputtime").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(lastinputtime)).ToLocalChecked());
  Nan::Set(target, Nan::New("displaysleep").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(displaysleep)).ToLocalChecked());
  Nan::Set(target, Nan::New("displaywake").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(displaywake)).ToLocalChecked());
}

NODE_MODULE(NativeExtension, InitAll)