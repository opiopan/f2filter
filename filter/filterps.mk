
filterps.dll: dlldata.obj filter_p.obj filter_i.obj
	link /dll /out:filterps.dll /def:filterps.def /entry:DllMain dlldata.obj filter_p.obj filter_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del filterps.dll
	@del filterps.lib
	@del filterps.exp
	@del dlldata.obj
	@del filter_p.obj
	@del filter_i.obj
