#ifndef ENTITY_EXTRACTOR_H
#define ENTITY_EXTRACTOR_H

#include <nan.h>
#include <mitie/named_entity_extractor.h>

class EntityExtractor : public Nan::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit EntityExtractor(string ner_file_path);
    ~EntityExtractor();

    static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static void Predict(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static Nan::Persistent<v8::Function> constructor;
    vector<string> tagstr_;
    mitie::named_entity_extractor ner_;
};

#endif
