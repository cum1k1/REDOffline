#!/usr/bin/env python2

import ROOT
import sys
import re
import glob
import datetime
from optparse import OptionParser

class BaseTreeOutput(object):
    # This is an interface class for printers that can show structured 
    # information about fields of some class with recursive tree walk.
    def __init__(self,file_name=None):
        if (file_name and file_name != ""):
            self.fh = open(file_name,"w")
        else:
            self.fh = sys.stdout
        print file_name, self.fh

    def __del__(self):
        self.fh.close()
        self.fh = None

    def Print(self,line):
        self.fh.write(line+"\n")

    def begin_all(self,list_):
        self.Print("begin_all")
        for s in list_:
            self.Print("\t"+s)
        return

    def end_all(self,list_):
        self.Print("end_all")
        for s in list_:
            self.Print("\t"+s)
        return

    def begin_tree(self,tree,descr):
        self.Print("begin_tree "+tree+" '"+descr+"'")
        return

    def end_tree(self):
        self.Print("end_tree")
        return

    def begin_class(self,var):
        self.Print("  begin_class "+var.GetTrueTypeName()+" "+var.GetName()+"")
        return

    def end_class(self):
        self.Print("  end_class")
        return

    def simple_type(self,var):
        self.Print("  simple_type "+var.GetTrueTypeName()+" "+var.GetName()+"")
        return

class CTreeOutput(BaseTreeOutput):
    def __init__(self,file_name=None):
        super(CTreeOutput,self).__init__(file_name)
        self.prefix = ""
        self.name = ""

    def begin_all(self,list_):
        self.Print("/*")
        for s in list_:
            self.Print(s)
        self.Print("*/")

    def end_all(self,list_):
        self.Print("/*")
        for s in list_:
            self.Print(s)
        self.Print("*/")

    def begin_tree(self,tree,descr):
        self.Print("// Parsing tree '%s' ('%s')" % (tree,descr))
        self.name = tree

    def end_tree(self):
        self.Print("")
        self.name = ""

    def begin_class(self,var):
        self.Print("%s%s %s = {%s" % (self.prefix,var.GetTrueTypeName(),var.GetName(),(" // "+var.GetTitle() if len(var.GetTitle())>0 else "")))
        self.prefix += "  "

    def end_class(self):
        self.prefix = self.prefix[0:-2]
        self.Print(self.prefix+("}," if len(self.prefix)>0 else "}"))

    def simple_type(self,var):
        name = var.GetName()
        for i in range(0,var.GetArrayDim()): name += "[%d]" % var.GetMaxIndex(i)
        vtype = var.GetTrueTypeName()
        match = re.search("<([^,]+).*(,allocator<\\1> ?)",vtype)
        if match: vtype = vtype.replace(match.group(2),"")
        self.Print("%s%s %s;%s" % (self.prefix,vtype,name,(" // "+var.GetTitle() if len(var.GetTitle())>0 else "")))

class HTMLTreeOutput(BaseTreeOutput):
    def __init__(self,file_name=""):
        super(HTMLTreeOutput,self).__init__(file_name)
        self.var_list = []

    def begin_all(self,l):
        self.Print("""
<html>
<title>REDFile data description</title>
<body>
<h1>REDFile data description</h1>
""")
        for s in l:
            self.Print(s+"<br>")

    def end_all(self,l):
        self.Print("<small>")
        for s in l:
            self.Print(s+"<br>")
        self.Print("</small>")
        self.Print("</body>\n</html>\n")

    def begin_tree(self,tree,descr):
        self.Print("""
<h3>REDFile storage tree '%s' ("%s")</h3>
<table border="1" cellpadding="5" cellpadding="0">
<tr><th>Name</th><th>Type</th><th>Units</th><th>Description</th></tr>
""" % (tree,descr))
#<caption>REDFile storage tree '%s'("%s")</caption>

    def end_tree(self):
        self.Print("\n</table>\n<br><hr>\n")

    def begin_class(self,var):
        #name = ("&gt;"*len(self.var_list))+var.GetTypeName()
        vtype = var.GetTrueTypeName()
        match = re.search("<(\w+).*(,allocator<\\1> ?)",vtype)
        if match: vtype = vtype.replace(match.group(2),"")
        vtype = vtype.replace("<","&lt;").replace(">","&gt;")
        for i in range(0,var.GetArrayDim()): vtype += "[%d]" % var.GetMaxIndex(i)
        self.Print("""<tr><th colspan="2" align="right">%s</th><td></td><td>%s</td></tr>""" % (vtype,var.GetTitle()))
        #self.simple_type(MyDataMember("@"+var.GetName()+".size()","Int_t","Number of objects"))
        self.var_list += [var.GetName()]

    def end_class(self):
        if (len(self.var_list)>0): del self.var_list[-1]
        if (len(self.var_list)>0): self.Print("<tr><th colspan=\"4\"></th></tr>")

    def simple_type(self,var):
        prefix = ".".join(self.var_list[1:])+"." if len(self.var_list)>1 else ""
        self.Print("""<tr><td><font color="grey">%s</font>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>""" % ((prefix,)+TWikiTreeOutput.prepare_var(var)))

    @staticmethod
    def prepare_var(var):
        name = var.GetName()
        vtype = var.GetTrueTypeName()
        match = re.search("<([^,]+).*(,allocator<\\1>)",vtype)
        if match: vtype = vtype.replace(match.group(2),"")
        vtype = vtype.replace("<","&lt;").replace(">","&gt;")
        for i in range(0,var.GetArrayDim()): vtype += "[%d]" % var.GetMaxIndex(i)
        descr = var.GetTitle()
        match = re.search("\[(\w+)\]",descr)
        if match:
            units = match.group(1) 
            descr = descr.replace(match.group(),"")
        else:
            units = ""
        return (name,vtype,units,descr)

class TWikiTreeOutput(HTMLTreeOutput):
    def __init__(self,file_name=""):
        super(TWikiTreeOutput,self).__init__(file_name)
        self.var_list = []

    def begin_all(self,l):
        self.Print("---+ REDFile data description\n")
        for s in l:
            self.Print(s+"<br>")
        self.Print("")

    def end_all(self,l):
        self.Print("<small>")
        for s in l:
            self.Print(s+"<br>")
        self.Print("</small>")

    def begin_tree(self,tree,descr):
        self.Print("---+++ REDFile storage tree '%s' (\"%s\")\n\n| Name | Type | Units | Description |" % (tree,descr))

    def end_tree(self):
        self.Print("")

    def begin_class(self,var):
        self.Print("| %s ||| %s |" % (var.GetTrueTypeName(),var.GetTitle()))
        self.var_list += [var.GetName()]

    def end_class(self):
        if (len(self.var_list)>0): del self.var_list[-1]
        pass

    def simple_type(self,var):
        prefix = ".".join(self.var_list[1:])+"." if len(self.var_list)>1 else ""
        self.Print("| %s%s | %s | %s | %s |" % ((prefix,)+TWikiTreeOutput.prepare_var(var)))

class MyDataMember:
    # This class is to fake a TDataMember for root object
    def __init__(self,name,type_,descr):
        self.name = name
        self.type_ = type_
        self.descr = descr
    def GetName(self):
        return self.name
    def GetTypeName(self):
        return self.type_
    def GetTrueTypeName(self):
        return self.type_
    def GetArrayDim(self):
        return 0
    def GetMaxIndex(self,idx):
        return 0
    def GetTitle(self):
        return self.descr


def generate_doc(cls, prev = "", title = ""):
#    print "++",cls
    objclass = cls.Class()
    data_list = objclass.GetListOfDataMembers()
    get_list = [fn for fn in objclass.GetListOfAllPublicMethods() if fn.GetName().startswith("Get") ]
#    for i in get_list: print i,i.GetReturnTypeName(),i.GetSignature()

    for data in data_list:

#        print data
        if not data.IsPersistent():
            # skip cache-only data members
            continue
        try:
            if data.GetTypeName().startswith("set<UInt_t"):
                # this doesn't fix so easy, name is changed
                raise AttributeError
            attr = getattr(ROOT, data.GetTypeName())
        except AttributeError:
            Printer.simple_type(data)
            continue

        if (not hasattr(attr, "Class")): 
            # Not ROOTified class
            Printer.simple_type(data)
            continue
        if (attr.Class() == ROOT.TClass.Class()):
            # skip pointer to TClass
            continue
        if (attr.Class() == objclass):
            # treat class itself as simple
            Printer.simple_type(data)
            continue
        if (attr.Class().InheritsFrom(ROOT.TCollection.Class()) and \
            not attr.Class().InheritsFrom(ROOT.TRefArray.Class()) ):
            # Unfortunately TClonesArray isn't a template so we don't know
            # exact type of data. Let's guess that out using return type of 
            # wrapper methods.
            base_name = data.GetName()
            match = re.match("^f?(Ref)?(\w+?)s?$",base_name)
            if match: base_name = match.group(2)
            small_list = [fn for fn in get_list 
                          if ("Get"+base_name in fn.GetName() and
                              not fn.GetReturnTypeName().startswith("const ") and
                              fn.GetListOfMethodArgs().GetSize()==1) ]
            if len(small_list)==1:
                next_type = small_list[0].GetReturnTypeName().replace("*","")
                if hasattr(ROOT, next_type):
                    next_obj = getattr(ROOT, next_type)
                    if True:
                        vname = data.GetName()
                    else:
                        vname = small_list[0].GetName()+"(#)"
                    vtype = data.GetTrueTypeName()
                    if vtype.endswith("*"):
                        vtype = vtype[0:-1]+"<"+next_type+">*"
                    else:
                        vtype = vtype+"<"+next_type+">"
                    Printer.begin_class(MyDataMember(vname,vtype,data.GetTitle()))
                    generate_doc(next_obj,".")
                    Printer.end_class()
                else:
                    print >>sys.stderr, "Can't find correct type for "+data.GetName()
                    Printer.simple_type(data)
            else:
                print >>sys.stderr, "Can't find correct type for "+data.GetName()
                Printer.simple_type(data)

        elif (attr.Class() == ROOT.TRef.Class() or \
              attr.Class().InheritsFrom(ROOT.TRefArray.Class()) ):
            # TRefs also doesn't provide exact data type by itself.
            # Let's guess that out using return type of wrapper methods.
            base_name = data.GetName()
            match = re.match("^f?(Ref)?(\w+?)s?$",base_name)
            if match: base_name = match.group(2)
            small_list = [fn for fn in get_list 
                          if ("Get"+base_name in fn.GetName() and
                              not fn.GetReturnTypeName().startswith("const ") and
                              fn.GetListOfMethodArgs().GetSize()<=1) ]
            if len(small_list)==1:
                next_type = small_list[0].GetReturnTypeName().replace("*","")
                if hasattr(ROOT, next_type):
                    next_obj = getattr(ROOT, next_type)
                    vtype = data.GetTrueTypeName()
                    if vtype.endswith("*"):
                        vtype = vtype[0:-1]+"<"+next_type+">*"
                    else:
                        vtype = vtype+"<"+next_type+">"
                    Printer.simple_type(MyDataMember(data.GetName(),vtype,data.GetTitle()))
                else:
                    print >>sys.stderr, "Can't find correct type for "+data.GetName()
                    Printer.simple_type(data)
            else:
                print >>sys.stderr, "Can't find correct type for "+data.GetName()
                Printer.simple_type(data)
        else:
            next_obj = getattr(ROOT, data.GetTypeName())
            Printer.begin_class(data)
            generate_doc(next_obj,prev+data.GetName()+".")
            Printer.end_class()

class Config(object):
    def __init__(self,conf_dir=None):
        if not conf_dir or conf_dir=="": conf_dir = "."
        with open(conf_dir+'/config.h') as fh:
            for line in fh:
                words = line.strip().split(' ')
                if (words[0]=='#define' and
                    (words[1].startswith('PACKAGE') or
                     words[1].startswith('BUILD'))):
                    val = " ".join(words[2:])
                    if len(val)>0:
                        if val[0]=='"': val = val[1:-1]
                        setattr(self,words[1],val)
        with open(conf_dir+'/config.mk') as fh:
            for line in fh:
                words = line.strip().split(' ')
                if (words[0].startswith('PYTHON')):
                    val = " ".join([w for w in words[2:] if w!="" and w!="="])
                    if len(val)>0:
                        if val[0]=='"': val = val[1:-1]
                        setattr(self,words[1],val)

if __name__ == '__main__':
    usage = "%prog [opts]"
    parser = OptionParser(usage)
    parser.add_option("-m",dest="mode",default="Base",help="set output mode (Base, HTML, C, Wiki)")
    parser.add_option("-d",dest="builddir",default="../build",help="set directory with build infrastructure")
    parser.add_option("-o",dest="outfile",default="",help="set output file name")
    options,args = parser.parse_args()

    if len(args) > 0:
        parser.print_help()
        exit(1)
    sys.argv = args

    print options
    if options.mode=='Base':
        Printer = BaseTreeOutput(options.outfile)
    elif options.mode=='HTML':
        Printer = HTMLTreeOutput(options.outfile)
    elif options.mode=='C':
        Printer = CTreeOutput(options.outfile)
    elif options.mode=='TWiki':
        Printer = TWikiTreeOutput(options.outfile)
    else:
        exit(1)

    config = Config(options.builddir)

    ROOT.gROOT.SetBatch()
    if ROOT.gSystem.Load(options.builddir+"/REDFile/libREDFile.so") < 0:
        print >>sys.stderr, "Error loading libREDFile.so"
        exit(0)

    #mod_dir = 'build/modules'
    #for mod in glob.glob(mod_dir+"/*/module*.so"):
    #    #ROOT.EXOROOT.LoadPlugin(mod)
    #    print "Found module "+mod

    #classes = ROOT.gClassTable
    #for m in ROOT.RED.__dict__.items():
    #    print "==",m,m[1]

    Printer.begin_all([config.BUILD_STRING])
    tree_list = [fn for fn in ROOT.RED.File.__dict__.items() 
                 if fn[0].startswith("Get") and fn[0].endswith("TreeName")]
    for fn in tree_list:
        base_name = fn[0][3:-8];
        try:
            tree_name   = getattr(ROOT.RED.File, "Get%sTreeName" % base_name)()
            branch_name = getattr(ROOT.RED.File, "Get%sBranchName" % base_name)()
            tree_descr  = getattr(ROOT.RED.File, "Get%sTreeDescription" % base_name)()
            class_name  = getattr(ROOT.RED.File, "Get%sClassName" % base_name)()
        except AttributeError:
            print >>sys.stderr, "Can't find tree description for "+base_name
            continue
#        print base_name, "(tree=%s branch=%s class=%s)" % (tree_name,branch_name,class_name)
        Printer.begin_tree(tree_name,tree_descr)
        if hasattr(ROOT, class_name):
            class_obj = getattr(ROOT, class_name)
            Printer.begin_class(MyDataMember(tree_name,class_name,tree_descr))
            generate_doc(class_obj)
            Printer.end_class()
        Printer.end_tree()
    Printer.end_all([
        "Build options",config.BUILD_CODE,config.BUILD_HOST,
        ("File auto-generated on (UTC) %s" % 
         (datetime.datetime.utcnow().strftime("%c"))),
    ])
