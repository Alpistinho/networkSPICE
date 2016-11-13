// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: component.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "component.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* Component_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Component_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* ComponentType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_component_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_component_2eproto() {
  protobuf_AddDesc_component_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "component.proto");
  GOOGLE_CHECK(file != NULL);
  Component_descriptor_ = file->message_type(0);
  static const int Component_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, componenttype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, nodes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, values_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, tolerances_),
  };
  Component_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Component_descriptor_,
      Component::internal_default_instance(),
      Component_offsets_,
      -1,
      -1,
      -1,
      sizeof(Component),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Component, _internal_metadata_));
  ComponentType_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_component_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Component_descriptor_, Component::internal_default_instance());
}

}  // namespace

void protobuf_ShutdownFile_component_2eproto() {
  Component_default_instance_.Shutdown();
  delete Component_reflection_;
}

void protobuf_InitDefaults_component_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  Component_default_instance_.DefaultConstruct();
  Component_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_component_2eproto_once_);
void protobuf_InitDefaults_component_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_component_2eproto_once_,
                 &protobuf_InitDefaults_component_2eproto_impl);
}
void protobuf_AddDesc_component_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_component_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017component.proto\"e\n\tComponent\022%\n\rcompon"
    "entType\030\001 \001(\0162\016.ComponentType\022\r\n\005nodes\030\002"
    " \003(\005\022\016\n\006values\030\003 \003(\002\022\022\n\ntolerances\030\004 \003(\002"
    "*:\n\rComponentType\022\014\n\010Resistor\020\000\022\r\n\tCapac"
    "itor\020\001\022\014\n\010Inductor\020\002b\006proto3", 188);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "component.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_component_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_component_2eproto_once_);
void protobuf_AddDesc_component_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_component_2eproto_once_,
                 &protobuf_AddDesc_component_2eproto_impl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_component_2eproto {
  StaticDescriptorInitializer_component_2eproto() {
    protobuf_AddDesc_component_2eproto();
  }
} static_descriptor_initializer_component_2eproto_;
const ::google::protobuf::EnumDescriptor* ComponentType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ComponentType_descriptor_;
}
bool ComponentType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Component::kComponentTypeFieldNumber;
const int Component::kNodesFieldNumber;
const int Component::kValuesFieldNumber;
const int Component::kTolerancesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Component::Component()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_component_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:Component)
}

void Component::InitAsDefaultInstance() {
}

Component::Component(const Component& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Component)
}

void Component::SharedCtor() {
  componenttype_ = 0;
  _cached_size_ = 0;
}

Component::~Component() {
  // @@protoc_insertion_point(destructor:Component)
  SharedDtor();
}

void Component::SharedDtor() {
}

void Component::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Component::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Component_descriptor_;
}

const Component& Component::default_instance() {
  protobuf_InitDefaults_component_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<Component> Component_default_instance_;

Component* Component::New(::google::protobuf::Arena* arena) const {
  Component* n = new Component;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Component::Clear() {
// @@protoc_insertion_point(message_clear_start:Component)
  componenttype_ = 0;
  nodes_.Clear();
  values_.Clear();
  tolerances_.Clear();
}

bool Component::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Component)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .ComponentType componentType = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_componenttype(static_cast< ::ComponentType >(value));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_nodes;
        break;
      }

      // repeated int32 nodes = 2;
      case 2: {
        if (tag == 18) {
         parse_nodes:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_nodes())));
        } else if (tag == 16) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 18, input, this->mutable_nodes())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_values;
        break;
      }

      // repeated float values = 3;
      case 3: {
        if (tag == 26) {
         parse_values:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_values())));
        } else if (tag == 29) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 26, input, this->mutable_values())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_tolerances;
        break;
      }

      // repeated float tolerances = 4;
      case 4: {
        if (tag == 34) {
         parse_tolerances:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_tolerances())));
        } else if (tag == 37) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 34, input, this->mutable_tolerances())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Component)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Component)
  return false;
#undef DO_
}

void Component::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Component)
  // optional .ComponentType componentType = 1;
  if (this->componenttype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->componenttype(), output);
  }

  // repeated int32 nodes = 2;
  if (this->nodes_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(2, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_nodes_cached_byte_size_);
  }
  for (int i = 0; i < this->nodes_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32NoTag(
      this->nodes(i), output);
  }

  // repeated float values = 3;
  if (this->values_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_values_cached_byte_size_);
  }
  for (int i = 0; i < this->values_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFloatNoTag(
      this->values(i), output);
  }

  // repeated float tolerances = 4;
  if (this->tolerances_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(4, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(_tolerances_cached_byte_size_);
  }
  for (int i = 0; i < this->tolerances_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFloatNoTag(
      this->tolerances(i), output);
  }

  // @@protoc_insertion_point(serialize_end:Component)
}

::google::protobuf::uint8* Component::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Component)
  // optional .ComponentType componentType = 1;
  if (this->componenttype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->componenttype(), target);
  }

  // repeated int32 nodes = 2;
  if (this->nodes_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      2,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _nodes_cached_byte_size_, target);
  }
  for (int i = 0; i < this->nodes_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32NoTagToArray(this->nodes(i), target);
  }

  // repeated float values = 3;
  if (this->values_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _values_cached_byte_size_, target);
  }
  for (int i = 0; i < this->values_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFloatNoTagToArray(this->values(i), target);
  }

  // repeated float tolerances = 4;
  if (this->tolerances_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      4,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
      _tolerances_cached_byte_size_, target);
  }
  for (int i = 0; i < this->tolerances_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteFloatNoTagToArray(this->tolerances(i), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Component)
  return target;
}

size_t Component::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Component)
  size_t total_size = 0;

  // optional .ComponentType componentType = 1;
  if (this->componenttype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->componenttype());
  }

  // repeated int32 nodes = 2;
  {
    size_t data_size = 0;
    unsigned int count = this->nodes_size();
    for (unsigned int i = 0; i < count; i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->nodes(i));
    }
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _nodes_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated float values = 3;
  {
    size_t data_size = 0;
    unsigned int count = this->values_size();
    data_size = 4UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _values_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated float tolerances = 4;
  {
    size_t data_size = 0;
    unsigned int count = this->tolerances_size();
    data_size = 4UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(data_size);
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _tolerances_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Component::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Component)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Component* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Component>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Component)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Component)
    UnsafeMergeFrom(*source);
  }
}

void Component::MergeFrom(const Component& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Component)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void Component::UnsafeMergeFrom(const Component& from) {
  GOOGLE_DCHECK(&from != this);
  nodes_.UnsafeMergeFrom(from.nodes_);
  values_.UnsafeMergeFrom(from.values_);
  tolerances_.UnsafeMergeFrom(from.tolerances_);
  if (from.componenttype() != 0) {
    set_componenttype(from.componenttype());
  }
}

void Component::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Component)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Component::CopyFrom(const Component& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Component)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool Component::IsInitialized() const {

  return true;
}

void Component::Swap(Component* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Component::InternalSwap(Component* other) {
  std::swap(componenttype_, other->componenttype_);
  nodes_.UnsafeArenaSwap(&other->nodes_);
  values_.UnsafeArenaSwap(&other->values_);
  tolerances_.UnsafeArenaSwap(&other->tolerances_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Component::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Component_descriptor_;
  metadata.reflection = Component_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Component

// optional .ComponentType componentType = 1;
void Component::clear_componenttype() {
  componenttype_ = 0;
}
::ComponentType Component::componenttype() const {
  // @@protoc_insertion_point(field_get:Component.componentType)
  return static_cast< ::ComponentType >(componenttype_);
}
void Component::set_componenttype(::ComponentType value) {
  
  componenttype_ = value;
  // @@protoc_insertion_point(field_set:Component.componentType)
}

// repeated int32 nodes = 2;
int Component::nodes_size() const {
  return nodes_.size();
}
void Component::clear_nodes() {
  nodes_.Clear();
}
::google::protobuf::int32 Component::nodes(int index) const {
  // @@protoc_insertion_point(field_get:Component.nodes)
  return nodes_.Get(index);
}
void Component::set_nodes(int index, ::google::protobuf::int32 value) {
  nodes_.Set(index, value);
  // @@protoc_insertion_point(field_set:Component.nodes)
}
void Component::add_nodes(::google::protobuf::int32 value) {
  nodes_.Add(value);
  // @@protoc_insertion_point(field_add:Component.nodes)
}
const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Component::nodes() const {
  // @@protoc_insertion_point(field_list:Component.nodes)
  return nodes_;
}
::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Component::mutable_nodes() {
  // @@protoc_insertion_point(field_mutable_list:Component.nodes)
  return &nodes_;
}

// repeated float values = 3;
int Component::values_size() const {
  return values_.size();
}
void Component::clear_values() {
  values_.Clear();
}
float Component::values(int index) const {
  // @@protoc_insertion_point(field_get:Component.values)
  return values_.Get(index);
}
void Component::set_values(int index, float value) {
  values_.Set(index, value);
  // @@protoc_insertion_point(field_set:Component.values)
}
void Component::add_values(float value) {
  values_.Add(value);
  // @@protoc_insertion_point(field_add:Component.values)
}
const ::google::protobuf::RepeatedField< float >&
Component::values() const {
  // @@protoc_insertion_point(field_list:Component.values)
  return values_;
}
::google::protobuf::RepeatedField< float >*
Component::mutable_values() {
  // @@protoc_insertion_point(field_mutable_list:Component.values)
  return &values_;
}

// repeated float tolerances = 4;
int Component::tolerances_size() const {
  return tolerances_.size();
}
void Component::clear_tolerances() {
  tolerances_.Clear();
}
float Component::tolerances(int index) const {
  // @@protoc_insertion_point(field_get:Component.tolerances)
  return tolerances_.Get(index);
}
void Component::set_tolerances(int index, float value) {
  tolerances_.Set(index, value);
  // @@protoc_insertion_point(field_set:Component.tolerances)
}
void Component::add_tolerances(float value) {
  tolerances_.Add(value);
  // @@protoc_insertion_point(field_add:Component.tolerances)
}
const ::google::protobuf::RepeatedField< float >&
Component::tolerances() const {
  // @@protoc_insertion_point(field_list:Component.tolerances)
  return tolerances_;
}
::google::protobuf::RepeatedField< float >*
Component::mutable_tolerances() {
  // @@protoc_insertion_point(field_mutable_list:Component.tolerances)
  return &tolerances_;
}

inline const Component* Component::internal_default_instance() {
  return &Component_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
