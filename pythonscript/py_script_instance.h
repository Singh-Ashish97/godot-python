#ifndef PY_SCRIPT_INSTANCE_H
#define PY_SCRIPT_INSTANCE_H


#include "script_language.h"


class PyScriptInstance : public ScriptInstance {
    Vector<Variant> members;
#if 0
friend class GDScript;
friend class GDFunction;
friend class GDFunctions;
friend class GDCompiler;

    Object *owner;
    Ref<GDScript> script;
#ifdef DEBUG_ENABLED
    Map<StringName,int> member_indices_cache; //used only for hot script reloading
#endif
    Vector<Variant> members;
    bool base_ref;


    void _ml_call_reversed(GDScript *sptr,const StringName& p_method,const Variant** p_args,int p_argcount);

public:

    _FORCE_INLINE_ Object* get_owner() { return owner; }
#endif
    virtual bool set(const StringName& p_name, const Variant& p_value);
    virtual bool get(const StringName& p_name, Variant &r_ret) const;
    virtual void get_property_list(List<PropertyInfo> *p_properties) const;
    virtual Variant::Type get_property_type(const StringName& p_name,bool *r_is_valid=NULL) const;


    virtual void get_method_list(List<MethodInfo> *p_list) const;
    virtual bool has_method(const StringName& p_method) const;
    virtual Variant call(const StringName& p_method,const Variant** p_args,int p_argcount,Variant::CallError &r_error);
    virtual void call_multilevel(const StringName& p_method,const Variant** p_args,int p_argcount);
    virtual void call_multilevel_reversed(const StringName& p_method,const Variant** p_args,int p_argcount);

    Variant debug_get_member_by_index(int p_idx) const { return members[p_idx]; }

    virtual void notification(int p_notification);

    virtual Ref<Script> get_script() const;

    virtual ScriptLanguage *get_language();

    void set_path(const String& p_path);

    void reload_members();

    virtual RPCMode get_rpc_mode(const StringName& p_method) const;
    virtual RPCMode get_rset_mode(const StringName& p_variable) const;


    PyScriptInstance();
    ~PyScriptInstance();

};

#endif // PY_SCRIPT_INSTANCE_H
