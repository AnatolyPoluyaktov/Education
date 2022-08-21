from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated
from .models import Counter
from django.db import IntegrityError
from django.db.transaction import TransactionManagementError


class CountView(APIView):
    permission_classes = (IsAuthenticated,)

    def get(self, request):
        counter, _ = Counter.objects.get_or_create(user=request.user)
        return Response(data=counter.count, status=200)

    def post(self, request):
        counter, _ = Counter.objects.get_or_create(user=request.user)

        counter.count += 1
        counter.save()
        return Response(data='ok', status=200)

    def delete(self, request):
        counter, _ = Counter.objects.get_or_create(user=request.user)
        val = counter.count

        if (val - 1) < 0:
            val = 0
        else:
            val -= 1

        counter.count = val
        counter.save()
        return Response(data="ok", status=200)
