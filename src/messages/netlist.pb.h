// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: netlist.proto

#ifndef PROTOBUF_netlist_2eproto__INCLUDED
#define PROTOBUF_netlist_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "component.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_netlist_2eproto();
void protobuf_InitDefaults_netlist_2eproto();
void protobuf_AssignDesc_netlist_2eproto();
void protobuf_ShutdownFile_netlist_2eproto();

class ConfigurationLine;
class Netlist;

enum SimulationType {
  Frequency = 0,
  Transient = 1,
  SimulationType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SimulationType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SimulationType_IsValid(int value);
const SimulationType SimulationType_MIN = Frequency;
const SimulationType SimulationType_MAX = Transient;
const int SimulationType_ARRAYSIZE = SimulationType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SimulationType_descriptor();
inline const ::std::string& SimulationType_Name(SimulationType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SimulationType_descriptor(), value);
}
inline bool SimulationType_Parse(
    const ::std::string& name, SimulationType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SimulationType>(
    SimulationType_descriptor(), name, value);
}
// ===================================================================

class ConfigurationLine : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ConfigurationLine) */ {
 public:
  ConfigurationLine();
  virtual ~ConfigurationLine();

  ConfigurationLine(const ConfigurationLine& from);

  inline ConfigurationLine& operator=(const ConfigurationLine& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ConfigurationLine& default_instance();

  static const ConfigurationLine* internal_default_instance();

  void Swap(ConfigurationLine* other);

  // implements Message ----------------------------------------------

  inline ConfigurationLine* New() const { return New(NULL); }

  ConfigurationLine* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConfigurationLine& from);
  void MergeFrom(const ConfigurationLine& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ConfigurationLine* other);
  void UnsafeMergeFrom(const ConfigurationLine& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .SimulationType type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::SimulationType type() const;
  void set_type(::SimulationType value);

  // optional double begin = 2;
  void clear_begin();
  static const int kBeginFieldNumber = 2;
  double begin() const;
  void set_begin(double value);

  // optional double end = 3;
  void clear_end();
  static const int kEndFieldNumber = 3;
  double end() const;
  void set_end(double value);

  // optional int64 points = 4;
  void clear_points();
  static const int kPointsFieldNumber = 4;
  ::google::protobuf::int64 points() const;
  void set_points(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:ConfigurationLine)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  double begin_;
  double end_;
  ::google::protobuf::int64 points_;
  int type_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_netlist_2eproto_impl();
  friend void  protobuf_AddDesc_netlist_2eproto_impl();
  friend void protobuf_AssignDesc_netlist_2eproto();
  friend void protobuf_ShutdownFile_netlist_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ConfigurationLine> ConfigurationLine_default_instance_;

// -------------------------------------------------------------------

class Netlist : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Netlist) */ {
 public:
  Netlist();
  virtual ~Netlist();

  Netlist(const Netlist& from);

  inline Netlist& operator=(const Netlist& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Netlist& default_instance();

  static const Netlist* internal_default_instance();

  void Swap(Netlist* other);

  // implements Message ----------------------------------------------

  inline Netlist* New() const { return New(NULL); }

  Netlist* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Netlist& from);
  void MergeFrom(const Netlist& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Netlist* other);
  void UnsafeMergeFrom(const Netlist& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Component component = 1;
  int component_size() const;
  void clear_component();
  static const int kComponentFieldNumber = 1;
  const ::Component& component(int index) const;
  ::Component* mutable_component(int index);
  ::Component* add_component();
  ::google::protobuf::RepeatedPtrField< ::Component >*
      mutable_component();
  const ::google::protobuf::RepeatedPtrField< ::Component >&
      component() const;

  // optional .ConfigurationLine config = 2;
  bool has_config() const;
  void clear_config();
  static const int kConfigFieldNumber = 2;
  const ::ConfigurationLine& config() const;
  ::ConfigurationLine* mutable_config();
  ::ConfigurationLine* release_config();
  void set_allocated_config(::ConfigurationLine* config);

  // @@protoc_insertion_point(class_scope:Netlist)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::Component > component_;
  ::ConfigurationLine* config_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_netlist_2eproto_impl();
  friend void  protobuf_AddDesc_netlist_2eproto_impl();
  friend void protobuf_AssignDesc_netlist_2eproto();
  friend void protobuf_ShutdownFile_netlist_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<Netlist> Netlist_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ConfigurationLine

// optional .SimulationType type = 1;
inline void ConfigurationLine::clear_type() {
  type_ = 0;
}
inline ::SimulationType ConfigurationLine::type() const {
  // @@protoc_insertion_point(field_get:ConfigurationLine.type)
  return static_cast< ::SimulationType >(type_);
}
inline void ConfigurationLine::set_type(::SimulationType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:ConfigurationLine.type)
}

// optional double begin = 2;
inline void ConfigurationLine::clear_begin() {
  begin_ = 0;
}
inline double ConfigurationLine::begin() const {
  // @@protoc_insertion_point(field_get:ConfigurationLine.begin)
  return begin_;
}
inline void ConfigurationLine::set_begin(double value) {
  
  begin_ = value;
  // @@protoc_insertion_point(field_set:ConfigurationLine.begin)
}

// optional double end = 3;
inline void ConfigurationLine::clear_end() {
  end_ = 0;
}
inline double ConfigurationLine::end() const {
  // @@protoc_insertion_point(field_get:ConfigurationLine.end)
  return end_;
}
inline void ConfigurationLine::set_end(double value) {
  
  end_ = value;
  // @@protoc_insertion_point(field_set:ConfigurationLine.end)
}

// optional int64 points = 4;
inline void ConfigurationLine::clear_points() {
  points_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ConfigurationLine::points() const {
  // @@protoc_insertion_point(field_get:ConfigurationLine.points)
  return points_;
}
inline void ConfigurationLine::set_points(::google::protobuf::int64 value) {
  
  points_ = value;
  // @@protoc_insertion_point(field_set:ConfigurationLine.points)
}

inline const ConfigurationLine* ConfigurationLine::internal_default_instance() {
  return &ConfigurationLine_default_instance_.get();
}
// -------------------------------------------------------------------

// Netlist

// repeated .Component component = 1;
inline int Netlist::component_size() const {
  return component_.size();
}
inline void Netlist::clear_component() {
  component_.Clear();
}
inline const ::Component& Netlist::component(int index) const {
  // @@protoc_insertion_point(field_get:Netlist.component)
  return component_.Get(index);
}
inline ::Component* Netlist::mutable_component(int index) {
  // @@protoc_insertion_point(field_mutable:Netlist.component)
  return component_.Mutable(index);
}
inline ::Component* Netlist::add_component() {
  // @@protoc_insertion_point(field_add:Netlist.component)
  return component_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Component >*
Netlist::mutable_component() {
  // @@protoc_insertion_point(field_mutable_list:Netlist.component)
  return &component_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Component >&
Netlist::component() const {
  // @@protoc_insertion_point(field_list:Netlist.component)
  return component_;
}

// optional .ConfigurationLine config = 2;
inline bool Netlist::has_config() const {
  return this != internal_default_instance() && config_ != NULL;
}
inline void Netlist::clear_config() {
  if (GetArenaNoVirtual() == NULL && config_ != NULL) delete config_;
  config_ = NULL;
}
inline const ::ConfigurationLine& Netlist::config() const {
  // @@protoc_insertion_point(field_get:Netlist.config)
  return config_ != NULL ? *config_
                         : *::ConfigurationLine::internal_default_instance();
}
inline ::ConfigurationLine* Netlist::mutable_config() {
  
  if (config_ == NULL) {
    config_ = new ::ConfigurationLine;
  }
  // @@protoc_insertion_point(field_mutable:Netlist.config)
  return config_;
}
inline ::ConfigurationLine* Netlist::release_config() {
  // @@protoc_insertion_point(field_release:Netlist.config)
  
  ::ConfigurationLine* temp = config_;
  config_ = NULL;
  return temp;
}
inline void Netlist::set_allocated_config(::ConfigurationLine* config) {
  delete config_;
  config_ = config;
  if (config) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Netlist.config)
}

inline const Netlist* Netlist::internal_default_instance() {
  return &Netlist_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::SimulationType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SimulationType>() {
  return ::SimulationType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_netlist_2eproto__INCLUDED