from django.shortcuts import render, redirect
from .forms import FileUploadForm
from django.http import  HttpResponseRedirect
from django.http import HttpResponse
from django.urls import reverse

def successfully_uploaded(request):
    return render(request, 'app/successfully_uploaded.html')

def upload_file(request):
    if request.method == "POST":
        form = FileUploadForm(request.POST, request.FILES)
        if form.is_valid():
            form.save()
            return  HttpResponseRedirect(reverse('app:successfully_uploaded'))

    else:
        form = FileUploadForm()
    return render(request, 'app/file_upload_form.html',
                  {'form': form})

